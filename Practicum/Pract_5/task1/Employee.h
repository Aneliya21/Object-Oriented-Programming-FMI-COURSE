#include <iostream>
#include "ErrorCode.h"

constexpr size_t MAX_STR_LEN=127;

class Employee{

    unsigned id;
    char name[MAX_STR_LEN + 1] = "";
    char position[MAX_STR_LEN + 1] = "";
    double salary = 0.0;

    /*Default-ен конструктор.
Конструктор с параметри.
double getSalary() const - връща заплатата на служителя.
ErrorCode updateSalary(double amount) - актуализира заплатата на служителя.*/
public:
    Employee() = default;
    Employee(unsigned id, const char* name, const char* position, double salary);

    double getSalary() const;
    ErrorCode updateSalary(double amount);
};
