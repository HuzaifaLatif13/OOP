#pragma once
#include"Employee.h"

class ProductionWorker : public Employee
{
private:
    int shift;
    double hourlyRate;
public:
    //constructor
   ProductionWorker(int _shift, double _hourlyRate, char* _empName, int _empNumber);
   //copy
   ProductionWorker(ProductionWorker& pw);
   //asign
   ProductionWorker operator=(ProductionWorker &pw);
   //setProductionWorker
   void setProductionWorker(int _shift, double _hourlyRate, char* _empName, int _empNumber);
   //setter & getter
   void setShift(int _shift);
   int getShift();
   void setHourlyRate(double _hourlyRate);
   double getHourlyRate();
   //display
   void PWdisplay();
};
