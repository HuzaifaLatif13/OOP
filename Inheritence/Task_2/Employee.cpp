#include"Employee.h"
#include<iostream>
#include<string.h>
using namespace std;

//constructor
Employee::Employee(char* _empName, int _empNumber)
{
    int x = strlen(_empName);
    empName = new char[x];
    strcpy(empName, _empName);
    empNumber = _empNumber;
}

//copy
Employee::Employee(Employee &e)
{
    this->empName = e.empName;
    this->empNumber = e.empNumber;
}

//assignment
Employee Employee::operator=(Employee &e)
{
    this->empName = e.empName;
    this->empNumber = e.empNumber;
}

//display
void Employee::empDisplay()
{
    cout<<"\nEmployee Name: "<<empName<<"\nEmployee Number: "<<empNumber;
}

//setEmpName
void Employee::setEmpName(char* _empName)
{
    int x = strlen(_empName);
    empName = new char[x];
    strcpy(empName, _empName);
}

//getEmpName
char* Employee::getEmpName()
{
    return empName;
}

//setEmpNumber
void Employee::setEmpNumber(int _empNumber)
{
    empNumber = _empNumber;
}

//getEmpNumber
int Employee::getEmpNumber()
{
    return empNumber;
}

//setEmployee
void Employee::setEmployee(char* _empName, int _empNumber)
{
    int x = strlen(_empName);
    empName = new char[x];
    strcpy(empName, _empName);
    empNumber = _empNumber;
}