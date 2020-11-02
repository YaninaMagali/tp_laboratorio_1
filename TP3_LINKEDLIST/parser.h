int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee);

int addEmployeesToFile(LinkedList* pArrayListEmployee, FILE* pFile);
int addEmployeesToBinaryFile(FILE* pFile, LinkedList* pArrayListEmployee);
