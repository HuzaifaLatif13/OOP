#include"ProductionWorker.h"
#include<iostream>
using namespace std;

//cons
ProductionWorker::ProductionWorker(int _shift, double _hourlyRate, char* _empName, int _empNumber) : Employee(_empName, _empNumber)
{
    shift = _shift;
    hourlyRate = _hourlyRate;
}

//copy
ProductionWorker::ProductionWorker(ProductionWorker& pw) : Employee(pw.getEmpName(), pw.getEmpNumber())
{
    this->shift = pw.shift;
    this->hourlyRate = pw.hourlyRate;
}

//assignm
ProductionWorker ProductionWorker::operator=(ProductionWorker& pw)
{
    this->shift = pw.shift;
    this->hourlyRate = pw.hourlyRate;
    this->setEmpName(pw.getEmpName());
    this->setEmpNumber(pw.getEmpNumber());
}

//display
void ProductionWorker::PWdisplay()
{
    empDisplay();
    cout<<"\nProduction Worker Shift is: ";
    if (shift==1)
    {
        cout<<"Day";
    }
    else if (shift==2)
    {
        cout<<"Night";
    }
    cout<<"\nProduction Worker Hourly Rate: "<<hourlyRate;
}

//setShift
void ProductionWorker::setShift(int _shift)
{
    shift = _shift;
}

//getShift
int ProductionWorker::getShift()
{
    return shift;
}

//setHourlyRate
void ProductionWorker::setHourlyRate(double _hourlyRate)
{
    hourlyRate = _hourlyRate;
}

//getHourlyRate
double ProductionWorker::getHourlyRate()
{
    return hourlyRate;
}

//setProductionWorker
void ProductionWorker::setProductionWorker(int _shift, double _hourlyRate, char* _empName, int _empNumber)
{
    shift = _shift;
    hourlyRate = _hourlyRate;
    this->setEmpName(_empName);
    this->setEmpNumber(_empNumber);
}