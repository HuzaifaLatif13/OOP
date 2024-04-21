#pragma once

class Employee
{
private:
    char* empName;
    int empNumber;
public:
    //overloaded
    Employee(char* _empName, int _empNumber);
    //employeeSetter
    void setEmployee(char* _empName, int _empNumber);
    //getter & setter
    void setEmpName(char* _empName);
    char* getEmpName();
    void setEmpNumber(int _empNumber);
    int getEmpNumber();
    //dislay
    void empDisplay();
    //copy
    Employee(Employee &e);
    //asignment
    Employee operator=(Employee &e);
};