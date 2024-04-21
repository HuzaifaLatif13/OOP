#pragma once
#include"Employee.h"

class ShiftSupervisor : public Employee
{
private:
    double annualSalary;
    double prodBonus;
public:
    //overload
    ShiftSupervisor(double _annualSalary, double _prodBonus, char* _empName, int _empNumber);
    //copy
    ShiftSupervisor(ShiftSupervisor &ss);
    //assignmnt
    ShiftSupervisor operator=(ShiftSupervisor& ss);
    //display
    void SSdisplay();
    //setShiftSupervisor
    void setSS(double _annualSalary, double _prodBonus, char* _empName, int _empNumber);
    //setter & getter
    void setAnnualSalary(double _annualSalary);
    double getAnnualSalary();
    void setProdBonus(double _prodBonus);
    double getProdBonus();
};