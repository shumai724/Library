#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

enum EmployeeType {
    FullTime,  // 社員
    PartTime   // アルバイト
};

struct Employee {
    string name;
    EmployeeType type;                // 社員かアルバイトか
    int max_shifts;                   // 最大シフト数（週5日）
    int assigned_shifts;              // 割り当てられたシフト数
    vector<string> unavailable_days;  // 希望休の日付リスト

    Employee(string n, EmployeeType t, int max_s, vector<string> unavail_days)
        : name(n), type(t), max_shifts(max_s), assigned_shifts(0), unavailable_days(unavail_days) {}
    
    // 希望休を確認
    bool isAvailable(string date) {
        return find(unavailable_days.begin(), unavailable_days.end(), date) == unavailable_days.end();
    }
};

struct Shift {
    string date;                      // シフトの日付
    int required_employees;           // 必要な人数
    vector<string> employees;         // シフトに割り当てられた従業員
    bool has_full_time;               // このシフトに社員が含まれているか

    Shift(string d, int req) : date(d), required_employees(req), has_full_time(false) {}
};

// シフト割り当て関数
void assignShift(vector<Employee>& employees, vector<Shift>& shifts) {
    for (auto& shift : shifts) {
        // まず社員を1人割り当てる
        bool full_time_assigned = false;
        for (auto& emp : employees) {
            if (emp.type == FullTime && emp.assigned_shifts < emp.max_shifts && emp.isAvailable(shift.date)) {
                shift.employees.push_back(emp.name);
                emp.assigned_shifts++;
                shift.has_full_time = true;
                full_time_assigned = true;
                break;
            }
        }

        // 社員が割り当てられなかった場合の警告
        if (!full_time_assigned) {
            cout << "Error: No full-time employee assigned for shift on " << shift.date << endl;
        }

        // 残りの従業員を割り当てる（社員またはアルバイト）
        for (auto& emp : employees) {
            if (shift.employees.size() >= shift.required_employees) {
                break;  // 必要人数に達したら終了
            }
            if (emp.assigned_shifts < emp.max_shifts && emp.isAvailable(shift.date)) {
                shift.employees.push_back(emp.name);
                emp.assigned_shifts++;
                if (emp.type == FullTime) {
                    shift.has_full_time = true;
                }
            }
        }
        
        // 割り当て人数が不足している場合の警告
        if (shift.employees.size() < shift.required_employees) {
            cout << "Warning: Not enough employees assigned for shift on " << shift.date << endl;
        }
    }
}

int main() {
    // 従業員リスト（名前、階級、最大シフト数、希望休リスト）
    vector<Employee> employees = {
        Employee("Alice", FullTime, 5, {"2024-10-01", "2024-10-05"}),
        Employee("Bob", PartTime, 5, {"2024-10-03"}),
        Employee("Charlie", FullTime, 5, {"2024-10-02", "2024-10-06"}),
        Employee("Dave", PartTime, 5, {"2024-10-04"})
    };

    // シフトリスト（日付、必要な人数）
    vector<Shift> shifts = {
        Shift("2024-10-01", 2),
        Shift("2024-10-02", 3),
        Shift("2024-10-03", 2),
        Shift("2024-10-04", 3),
        Shift("2024-10-05", 2),
        Shift("2024-10-06", 2),
        Shift("2024-10-07", 1)
    };

    // シフト割り当て
    assignShift(employees, shifts);

    // 結果を表示
    for (const auto& shift : shifts) {
        cout << "Shift on " << shift.date << " (Required: " << shift.required_employees << "): ";
        for (const auto& emp : shift.employees) {
            cout << emp << " ";
        }
        cout << endl;
    }

    return 0;
}
