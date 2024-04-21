#include"Employee.h"
#include"ProductionWorker.h"
#include"TeamLeader.h"

#include<iostream>
using namespace std;

void inputTeamLeader(double &_monBonus, int &_reqTH, int &_attTH, int &_shift, double &_hourlyRate, char* _empName, int &_empNumber)
{
    cout<<"\n\tEnter TeamLeader Data!!!\n";
    cout<<"\nEnter TeamLeader name: ";
    cin>>_empName;
    cout<<"\nEnter TeamLeader number: ";
    cin>>_empNumber;
    cout<<"\n\tSelect Shift\n1. Day Shift\n2. Night Shift\nEnter answer(1-2): ";
    cin>>_shift;
    while (_shift!=1 && _shift!=2)
    {
        cout<<"\nWrong Choice entered.\nEnter again(1-2): ";
        cin>>_shift;
    }
    cout<<"\nEnter Hourly Pay Rate: ";
    cin>>_hourlyRate;
    cout<<"\nEnter Monthly Bonus: ";
    cin>>_monBonus;
    cout<<"\nEnter Required Training Hours: ";
    cin>>_reqTH;
    cout<<"\nEnter Attended Training Hours: ";
    cin>>_attTH;
}

int main()
{
    char _empName[50];
    int _empNumber, _shift, _reqTH, _attTH;
    double _hourlyRate, _monBonus;

    cout<<"\n\tEnter Employee Data!!!\n";
    cout<<"\nEnter Employee name: ";
    cin>>_empName;
    cout<<"\nEnter Employee number: ";
    cin>>_empNumber;
    //static
    Employee e1(_empName, _empNumber);
    
    cout<<"\n\tEnter Employee Data!!!\n";
    cout<<"\nEnter Employee name: ";
    cin>>_empName;
    cout<<"\nEnter Employee number: ";
    cin>>_empNumber;
    //heap
    Employee* e2;
    e2 = new Employee(_empName, _empNumber);

    cout<<"\n<------------------------------------------------------->\n";
    e1.empDisplay();
    cout<<"\n\n";
    e2->empDisplay();

    cout<<"\n<------------------------------------------------------->\n";

    cout<<"\n\tEnter Production Worker Data!!!\n";
    cout<<"\nEnter Production Worker name: ";
    cin>>_empName;
    cout<<"\nEnter Production Worker number: ";
    cin>>_empNumber;
    cout<<"\n\tSelect Shift\n1. Day Shift\n2. Night Shift\nEnter answer(1-2): ";
    cin>>_shift;
    while (_shift!=1 && _shift!=2)
    {
        cout<<"\nWrong Choice entered.\nEnter again(1-2): ";
        cin>>_shift;
    }
    cout<<"\nEnter Hourly Pay Rate: ";
    cin>>_hourlyRate;
    //static
    ProductionWorker p1(_shift, _hourlyRate, _empName, _empNumber);
    
    cout<<"\n\tEnter Production Worker Data!!!\n";
    cout<<"\nEnter Production Worker name: ";
    cin>>_empName;
    cout<<"\nEnter Production Worker number: ";
    cin>>_empNumber;
    cout<<"\n\tSelect Shift\n1. Day Shift\n2. Night Shift\nEnter answer(1-2): ";
    cin>>_shift;
    while (_shift!=1 && _shift!=2)
    {
        cout<<"\nWrong Choice entered.\nEnter again(1-2): ";
        cin>>_shift;
    }
    cout<<"\nEnter Hourly Pay Rate: ";
    cin>>_hourlyRate;
    //heap
    ProductionWorker* p2;
    p2 = new ProductionWorker(_shift, _hourlyRate, _empName, _empNumber);

    cout<<"\n<------------------------------------------------------->\n";
    p1.PWdisplay();
    cout<<"\n\n";
    p2->PWdisplay();

    cout<<"\n<------------------------------------------------------->\n";
    int n;
    cout<<"\nEnter TeamLeader numbers: ";
    cin>>n;
    TeamLeader** tl;
    tl = new TeamLeader*[n];
    for (int i=0; i<n ; i++)
    {
        inputTeamLeader(_monBonus, _reqTH, _attTH, _shift, _hourlyRate, _empName, _empNumber);
        tl[i] = new TeamLeader(_monBonus, _reqTH, _attTH, _shift, _hourlyRate, _empName, _empNumber);
    }
    cout<<"\n<------------------------------------------------------->\n";
    for (int i=0; i<n ; i++)
    {
        tl[i]->TLdisplay();
        cout<<"\n\n";
    }
    
    //deallocation
    delete[] tl;
    cout<<"\nMemory Deallocate!!!\nProgram End!";

    return 0;
}