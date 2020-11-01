#ifndef EMPLOYEES_H_INCLUDED
#define EMPLOYEES_H_INCLUDED
typedef struct
{
    int employeeId;
    char employeeName[20];
    char employeeSurname[20];
    float employeeSalary;
}sEmployee;

void addEmployee(sEmployee* employee);

#endif // EMPLOYEES_H_INCLUDED
