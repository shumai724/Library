#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Employee {
    string name;
    int max_shifts; // 最大シフト数
    int assigned_shifts; // 割り当てられたシフト数

    Employee(string n, int max_s) : name(n), max_shifts(max_s), assigned_shifts(0) {}
};

struct Shift {
    string date; // シフトの日付
    vector<string> employees; // シフトに割り当てられた従業員名
};

void assignShift(vector<Employee>& employees, vector<Shift>& shifts) {
    for (auto& shift : shifts) {
        for (auto& emp : employees) {
            // もし従業員のシフトが最大数に達していなければ、その日付のシフトに割り当てる
            if (emp.assigned_shifts < emp.max_shifts) {
                shift.employees.push_back(emp.name);
                emp.assigned_shifts++;
                break; // 次のシフトに進む
            }
        }
    }
}

int main() {
    vector<Employee> employees = {
        Employee("Alice", 3),
        Employee("Bob", 2),
        Employee("Charlie", 3)
    };

    vector<Shift> shifts = {
        {"2024-10-01", {}},
        {"2024-10-02", {}},
        {"2024-10-03", {}},
        {"2024-10-04", {}}
    };

    assignShift(employees, shifts);

    // 結果を表示
    for (const auto& shift : shifts) {
        cout << "Shift on " << shift.date << ": ";
        for (const auto& emp : shift.employees) {
            cout << emp << " ";
        }
        cout << endl;
    }

    return 0;
}
