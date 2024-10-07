#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>
#include <algorithm> // 追加: std::find を使用するために必要
#include <ctime>
#include <sstream>
#include <iomanip>
using namespace std;

// 前のコードから必要な構造体を持ってくる
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
    vector<string> unavailable_days; // 希望休

    Employee(string n, EmployeeType t, int max_s, vector<string> unavail_days)
        : name(n), type(t), max_shifts(max_s), assigned_shifts(0), unavailable_days(unavail_days) {}
};

struct Shift {
    string date;
    string weekday;
    int required_employees;
    vector<string> employees;

    Shift(string d, string wd, int req) : date(d), weekday(wd), required_employees(req) {}
};

// 名前から従業員を見つける関数
const Employee* findEmployeeByName(const vector<Employee>& employees, const string& name) {
    for (const auto& emp : employees) {
        if (emp.name == name) {
            return &emp;
        }
    }
    return nullptr; // 見つからなかった場合
}

// 日付をパースする関数 (例: "2024-10-01" -> tm構造体)
tm parseDate(const std::string& dateStr) {
    tm date = {};
    std::stringstream ss(dateStr);
    ss >> std::get_time(&date, "%Y-%m-%d");
    date.tm_isdst = -1; // サマータイムの情報を無視
    mktime(&date); // tm構造体を正規化
    return date;
}

// 1週間の開始日かどうかを判定する関数
bool isNewWeek(const std::string& currentWeekStart, const std::string& currentDate) {
    tm weekStart = parseDate(currentWeekStart);
    tm date = parseDate(currentDate);

    // 同じ週かどうかを確認するため、年と週番号を比較
    return (date.tm_yday / 7) != (weekStart.tm_yday / 7);
}

// 従業員がシフトに入ることができるかどうかをチェックする関数
bool isAvailable(const Employee& emp, const Shift& shift) {
    // 希望休と重なっていないかをチェック (unavailable_daysを使用)
    for (const auto& rest_day : emp.unavailable_days) {
        if (rest_day == shift.date) {
            return false;
        }
    }
    return true;
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

// 曜日を取得する関数（前の関数）
string getWeekday(const string& date) {
    struct tm time_struct = {};
    strptime(date.c_str(), "%Y-%m-%d", &time_struct);
    mktime(&time_struct);

    const char* weekdays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return weekdays[time_struct.tm_wday];
}

// 従業員リストをファイルから読み込む（前の関数）
vector<Employee> loadEmployees(const string& filename) {
    vector<Employee> employees;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string name, type_str, max_shifts_str, token;
        vector<string> unavailable_days;

        getline(ss, name, ',');
        getline(ss, type_str, ',');
        getline(ss, max_shifts_str, ',');

        EmployeeType type = (type_str == "FullTime") ? FullTime : PartTime;
        int max_shifts = stoi(max_shifts_str);

        while (getline(ss, token, ',')) {
            vector<string> days = expandDateRange(token);
            unavailable_days.insert(unavailable_days.end(), days.begin(), days.end());
        }

        employees.emplace_back(name, type, max_shifts, unavailable_days);
    }

    return employees;
}

// シフトリストをファイルから読み込む（前の関数）
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

// シフト割り当て関数（前の関数）
void assignShift(vector<Employee>& employees, vector<Shift>& shifts) {
    // 1週間に最低2回シフトに入れるための処理
    unordered_map<string, int> employeeWeeklyShiftCount;
    string currentWeekStart = shifts.front().date; // 最初の週の始まりを保存

    for (auto& shift : shifts) {
        // 新しい週が始まった場合はカウントをリセット
        if (isNewWeek(currentWeekStart, shift.date)) {
            employeeWeeklyShiftCount.clear(); // カウントをリセット
            currentWeekStart = shift.date;    // 新しい週の始まりを更新
        }

        int assignedFullTime = 0;
        int assignedTotal = 0;

        // 必要な従業員数を満たすまで割り当て
        for (auto& emp : employees) {

            // 従業員が既にその日シフトに入っているかを確認
            if (isAvailable(emp, shift)) {

                if(employeeWeeklyShiftCount[emp.name] < 5){
                   shift.employees.push_back(emp.name);
                   employeeWeeklyShiftCount[emp.name]++;

                   // フルタイム従業員が1人以上入っているか確認
                   if(emp.type == FullTime) {
                       assignedFullTime++;
                    }

                    assignedTotal++;

                // 必要人数に達したら終了
                if (assignedTotal >= shift.required_employees && assignedFullTime >= 1) {
                    break;
                }
                }
            }
        }

        // 予定されている従業員数に対して実際に割り当てられている従業員の数を制限
        int plannedEmployeesCount = shift.required_employees;
        int maxActualEmployeesCount = plannedEmployeesCount + 2;

        // 週に2回以上シフトに入っていない従業員がいる場合、シフトを追加
        for (auto& emp : employees) {
            if (employeeWeeklyShiftCount[emp.name] < 2) {
                // シフトに追加可能場合
                if (isAvailable(emp, shift)) {
                    // 実際に割り当てられる人数が最大人数を超えない場合のみ追加
                    if (shift.employees.size() < maxActualEmployeesCount) {
                        shift.employees.push_back(emp.name);
                        employeeWeeklyShiftCount[emp.name]++;
                    }
                }
            }
        }
    }
}


// 表形式でシフトの結果をCSVファイルに出力する関数
void printShiftTableToCSV(const vector<Employee>& employees, const vector<Shift>& shifts, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file for writing: " << filename << endl;
        return;
    }

    // ヘッダー行（従業員名を横に並べる）
    file << "Date/Weekday";
    for (const auto& emp : employees) {
        file << "," << emp.name;
    }
    file << endl;

    // 各シフトの日にちとその従業員の担当を出力
    for (const auto& shift : shifts) {
        file << shift.date + " (" + shift.weekday + ")"; // 日付と曜日

        // 各従業員がそのシフトに入っているか確認し、◯を出力
        for (const auto& emp : employees) {
            if (std::find(shift.employees.begin(), shift.employees.end(), emp.name) != shift.employees.end()) {
                file << ",◯"; // シフトに割り当てられている
            } else {
                file << ",-"; // シフトに割り当てられていない
            }
        }
        file << endl;
    }

    file.close();
    cout << "Shift schedule saved to " << filename << endl;
}

// 各日時にシフトに入る従業員をリストアップしたファイルを作成する関数
// シフトに入っている従業員のカウントと予定数を表示するように修正
void printShiftEmployeeListToFile(const vector<Employee>& employees, const vector<Shift>& shifts, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file for writing: " << filename << endl;
        return;
    }

    for (const auto& shift : shifts) {
        // シフトに入っている従業員の数（研修アルバイトはカウントしない）
        int actualEmployeesCount = 0;
        for (const auto& empName : shift.employees) {
            const Employee* emp = findEmployeeByName(employees, empName);
            if (emp && emp->type != TraineePartTime) {
                actualEmployeesCount++;
            }
        }

        file << "Shift on " << shift.date << " (" << shift.weekday << "):\n";
        file << "Planned employees: " << shift.required_employees << ", Actual employees: " << actualEmployeesCount << "\n";

        for (const auto& empName : shift.employees) {
            const Employee* emp = findEmployeeByName(employees, empName);
            if (emp) {
                if (emp->type == PartTime) {
                    file << "- " << emp->name << " (アルバイト)" << endl;
                } else if (emp->type == TraineePartTime) {
                    file << "- " << emp->name << " (研修)" << endl;
                } else {
                    file << "- " << emp->name << endl;
                }
            }
        }
        file << endl; // シフトごとの区切り
    }

    file.close();
    cout << "Shift employee list with planned and actual employee count saved to " << filename << endl;
}

int main() {
    // ファイルから従業員リストとシフトリストを読み込む
    vector<Employee> employees = loadEmployees("employees.txt");
    vector<Shift> shifts = loadShifts("shifts.txt");

    // シフト割り当て
    assignShift(employees, shifts);

    // 結果をCSVファイル形式で出力
    printShiftTableToCSV(employees, shifts, "shift_schedule.csv");

    // シフトごとの従業員リストをファイルに出力
    printShiftEmployeeListToFile(employees, shifts, "shift_employee_list.txt");

    return 0;
}
