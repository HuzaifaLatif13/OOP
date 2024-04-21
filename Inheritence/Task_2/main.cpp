#include"ShiftSupervisor.h"
#include"Employee.h"

#include<iostream>
using namespace std;

void inputSS(double &_annualSalary, double &_prodBonus, char* _empName, int &_empNumber)
{
    cout<<"\n\tEnter ShiftSupervisor Data!!!\n";
    cout<<"\nEnter Employee name: ";
    cin>>_empName;
    cout<<"\nEnter Employee number: ";
    cin>>_empNumber;
    cout<<"\nEnter Annual Salary: ";
    cin>>_annualSalary;
    cout<<"\nEnter Production Bonus: ";
    cin>>_prodBonus;
}

int main()
{
    double _annualSalary, _prodBonus; char _empName[50]; int _empNumber;
    int n;
    cout<<"\nEnter Shift Supervisor numbers: ";
    cin>>n;

    ShiftSupervisor** ss;
    ss = new ShiftSupervisor*[n];

    for (int i=0; i<n ; i++)
    {
        inputSS(_annualSalary, _prodBonus, _empName, _empNumber);
        ss[i] = new ShiftSupervisor(_annualSalary, _prodBonus, _empName, _empNumber);
    }
    
    cout<<"\n<----------------------------------->\n";
    for (int i=0; i<n ; i++)
    {
        ss[i]->SSdisplay();
        cout<<"\n\n";
    }
    
    cout<<"\n<----------------------------------->\n";
    delete[] ss;
    cout<<"\nDeallocated!\nProgram End\n";

    return 0;
}