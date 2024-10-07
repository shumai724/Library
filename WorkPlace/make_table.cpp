#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <unordered_set>
#include <ctime>
#include <algorithm>

using namespace std;

enum EmployeeType {
    FullTime,      // 正社員
    PartTime,      // アルバイト
    TraineePartTime // 研修アルバイト
};

struct Employee {
    string name;
    EmployeeType type;
    int max_shifts;
    int assigned_shifts;
    vector<string> unavailable_days;

    Employee(string n, EmployeeType t, int max_s, const vector<string>& unavail_days)
        : name(n), type(t), max_shifts(max_s), assigned_shifts(0), unavailable_days(unavail_days) {}
};

struct Shift {
    string date;
    string weekday;
    int required_employees;
    vector<string> employees;  // シフトに割り当てられた従業員のリスト

    Shift(string d, string wd, int req) : date(d), weekday(wd), required_employees(req) {}
};

// 名前から従業員を見つける関数
const Employee* findEmployeeByName(const vector<Employee>& employees, const string& name) {
    for (const auto& emp : employees) {
        if (emp.name == name) {
            return &emp;
        }
    }
    return nullptr;
}

// 日付文字列を日付範囲に変換してベクターに追加する（前の関数）
vector<string> expandDateRange(const string& range) {
    vector<string> result;
    string start_date, end_date;
    stringstream ss(range);

    if (range.find("~") != string::npos) {
        getline(ss, start_date, '~');
        getline(ss, end_date);

        // 日付を tm 構造体に変換
        struct tm tm_start = {}, tm_end = {};
        strptime(start_date.c_str(), "%Y-%m-%d", &tm_start);
        strptime(end_date.c_str(), "%Y-%m-%d", &tm_end);

        time_t start_time = mktime(&tm_start);
        time_t end_time = mktime(&tm_end);

        // 日付範囲を展開
        for (time_t t = start_time; t <= end_time; t += 24 * 60 * 60) {
            char buffer[11];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d", localtime(&t));
            result.push_back(string(buffer));
        }
    } else {
        result.push_back(range);  // 単一の日付の場合
    }

    return result;
}

// employees.txt から従業員データを読み込む関数
vector<Employee> readEmployees(const string& filename) {
    vector<Employee> employees;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string name, type_str, day_range;
        int max_shifts;
        vector<string> unavailable_days;

        // まず従業員の基本情報を取得
        getline(ss, name, ',');
        getline(ss, type_str, ',');
        ss >> max_shifts;
        ss.ignore(); // カンマを無視

        // 希望休を全て取得 (カンマ区切りで複数)
        while (getline(ss, day_range, ',')) {
            unavailable_days.push_back(day_range);
        }

        // 従業員のタイプを判定
        EmployeeType type;
        if (type_str == "FullTime") {
            type = FullTime;
        } else if (type_str == "PartTime") {
            type = PartTime;
        } else if (type_str == "TraineePartTime") {
            type = TraineePartTime;
        }

        // Employee オブジェクトを作成してリストに追加
        employees.emplace_back(name, type, max_shifts, unavailable_days);
    }

    return employees;
}

string getWeekday(const string& date) {
    struct tm time_struct = {};
    strptime(date.c_str(), "%Y-%m-%d", &time_struct);
    mktime(&time_struct);

    const char* weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return weekdays[time_struct.tm_wday];
}


vector<Shift> loadShifts(const string& filename) {
    vector<Shift> shifts;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string date, required_employees_str;

        getline(ss, date, ',');
        getline(ss, required_employees_str, ',');

        string weekday = getWeekday(date);
        int required_employees = stoi(required_employees_str);

        shifts.emplace_back(date, weekday, required_employees);
    }

    return shifts;
}

// すでにシフトに割り当てられているかを確認する関数
bool isAlreadyAssigned(const Shift& shift, const string& employeeName) {
    return find(shift.employees.begin(), shift.employees.end(), employeeName) != shift.employees.end();
}


// 従業員がシフトに入ることができるかを確認する関数
bool isAvailable(const Employee& emp, const Shift& shift) {
    // 希望休をチェック
    for (const auto& rest : emp.unavailable_days) {
        // 希望休が範囲か単一日かを判断
        if (rest.find('~') != string::npos) {
            // 日付範囲 (例: "2024-10-03~2024-10-04")
            string start_date = rest.substr(0, rest.find('~'));
            string end_date = rest.substr(rest.find('~') + 1);

            // シフト日が範囲内にあるか確認
            if (shift.date >= start_date && shift.date <= end_date) {
                return false;
            }
        } else {
            // 単一日 (例: "2024-10-03")
            if (shift.date == rest) {
                return false;
            }
        }

    }
    return emp.assigned_shifts < emp.max_shifts;
}

// シフト割り当て関数
void assignShift(vector<Employee>& employees, vector<Shift>& shifts) {
    unordered_map<string, int> employeeWeeklyShiftCount;  // 1週間のシフト数カウント
    string currentWeekStart = shifts.front().date;        // 最初の週の開始日

    for (auto& shift : shifts) {
        // 実際の従業員数と予定従業員数を比較しながらシフト割り当て
        int assignedEmployees = 0;
        unordered_set<string> assignedNames;  // すでに割り当てられた従業員を記録

        for (auto& emp : employees) {
            // 必要な従業員数に達している場合はループを終了
            if (assignedEmployees >= shift.required_employees) {
                break;
            }

            // 従業員がシフトに入れるかどうか、そしてすでに割り当てられていないかを確認
            if (isAvailable(emp, shift) && !isAlreadyAssigned(shift, emp.name)) {
                shift.employees.push_back(emp.name);
                emp.assigned_shifts++;
                assignedNames.insert(emp.name);

                // 研修アルバイト以外はカウントに含める
                if (emp.type != TraineePartTime) {
                    assignedEmployees++;
                }
            }
        }

        // 予定人数を満たさない場合、さらに従業員を追加
        for (auto& emp : employees) {
            if (assignedEmployees >= shift.required_employees) {
                break;
            }

            // 研修アルバイト以外の従業員を再度割り当てる
            if (emp.type != TraineePartTime && isAvailable(emp, shift) && !isAlreadyAssigned(shift, emp.name)) {
                shift.employees.push_back(emp.name);
                emp.assigned_shifts++;
                assignedEmployees++;
                assignedNames.insert(emp.name);
            }
        }

        // 最後に、同じ従業員が二重にカウントされないようにする
        shift.employees.erase(unique(shift.employees.begin(), shift.employees.end()), shift.employees.end());

        // 最後に必要人数をチェックして警告を出す（例: 人数不足の場合）
        if (assignedEmployees < shift.required_employees) {
            cout << "Warning: Shift on " << shift.date << " is understaffed. Assigned: " 
                 << assignedEmployees << " out of " << shift.required_employees << " required.\n";
        }
    }
}



// CSV出力
void printShiftTableToCSV(const vector<Shift>& shifts, const string& filename) {
    ofstream file(filename);

    // ヘッダー
    file << "Date,Weekday,Planned Employees,Actual Employees,Employee List\n";

    for (const auto& shift : shifts) {
        file << shift.date << "," << shift.weekday << "," << shift.required_employees << "," << shift.employees.size() << ",";
        for (const auto& emp_name : shift.employees) {
            file << emp_name << " ";
        }
        file << "\n";
    }

    file.close();
}


int main() {
    vector<Employee> employees = readEmployees("Employees.txt");

    vector<Shift> shifts = loadShifts("shifts.txt");

    assignShift(employees, shifts);

    printShiftTableToCSV(shifts, "shift_employee_list.csv");

    return 0;
}
