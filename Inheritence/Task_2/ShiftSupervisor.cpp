#include"ShiftSupervisor.h"
#include<iostream>
using namespace std;

//overload
ShiftSupervisor::ShiftSupervisor(double _annualSalary, double _prodBonus, char* _empName, int _empNumber) : Employee(_empName, _empNumber)
{
    annualSalary = _annualSalary;
    prodBonus = _prodBonus;
}

//copy
ShiftSupervisor::ShiftSupervisor(ShiftSupervisor &ss) : Employee(ss.getEmpName(), ss.getEmpNumber())
{
    annualSalary = ss.annualSalary;
    prodBonus = ss.prodBonus;
}

//assignment
ShiftSupervisor ShiftSupervisor::operator=(ShiftSupervisor &ss)
{
    annualSalary = ss.annualSalary;
    prodBonus = ss.prodBonus;
    setEmpName(ss.getEmpName());
    setEmpNumber(ss.getEmpNumber());
}

//display
void ShiftSupervisor::SSdisplay()
{
    empDisplay();
    cout<<"\nAnnual Salary: "<<annualSalary<<"\nProduction Bonus: "<<prodBonus;
}

//setAnnualSalary
void ShiftSupervisor::setAnnualSalary(double _annualSalary)
{
    annualSalary = _annualSalary;
}
//getAnnualSalary
double ShiftSupervisor::getAnnualSalary()
{
    return annualSalary;
}

//setProdBonus
void ShiftSupervisor::setProdBonus(double _prodBonus)
{
    prodBonus = _prodBonus;
}
//getProdBonus
double ShiftSupervisor::getProdBonus()
{
    return prodBonus;
}