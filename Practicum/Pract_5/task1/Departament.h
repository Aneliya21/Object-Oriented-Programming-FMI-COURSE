#include "Employee.h"

constexpr size_t MAX_EMPLS_COUNT = 15;

class Departament{
    char name[MAX_STR_LEN + 1] = "";
    Employee employees[MAX_EMPLS_COUNT];
    size_t countOfEmployees = 0;

public:
    Departament() = default;
    Departament(const char* name);

    ErrorCode addEmployee(const Employee& employee);
    ErrorCode removeEmployee(size_t id);


};