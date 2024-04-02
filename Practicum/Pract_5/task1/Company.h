#include "Departament.h"

constexpr size_t MAX_DEPARTAMENTS= 8;

class Company{
    Departament departaments[MAX_DEPARTAMENTS];
    unsigned countOfDepartament = 0;

public:
    Company() = default;

    ErrorCode addDepartament(const char* name);
    ErrorCode removeDepartament(const char* name);
    ErrorCode addEmployeeToDepartament(const char* departamentName, const Employee& employee);
    ErrorCode removeEmployeeFromDepartament(const char* departamentName, unsigned id);
};
