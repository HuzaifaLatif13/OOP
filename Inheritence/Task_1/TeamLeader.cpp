#include"TeamLeader.h"
#include<iostream>
using namespace std;

//overload cons
TeamLeader::TeamLeader(double _monBonus, int _reqTH, int _attTH, int _shift, double _hourlyRate, char* _empName, int _empNumber) : ProductionWorker(_shift, _hourlyRate, _empName, _empNumber)
{
    monBonus = _monBonus;
    reqTH = _reqTH;
    attTH = _attTH;
}

//copy
TeamLeader::TeamLeader(TeamLeader &tl) : ProductionWorker(tl.getShift(), tl.getHourlyRate(), tl.getEmpName(), tl.getEmpNumber())
{
    monBonus = tl.monBonus;
    reqTH = tl.reqTH;
    attTH = tl.attTH;
}

//assignment
TeamLeader TeamLeader::operator=(TeamLeader& tl)
{
    monBonus = tl.monBonus;
    reqTH = tl.reqTH;
    attTH = tl.attTH;
    setShift(tl.getShift());
    setHourlyRate(tl.getHourlyRate());
    setEmpName(tl.getEmpName());
    setEmpNumber(tl.getEmpNumber());
}

//display
void TeamLeader::TLdisplay()
{
    PWdisplay();
    cout<<"\nMonthly Bonus: "<<monBonus<<"\nRequired Training Hours: "<<reqTH<<"\nAttended Training Hours: "<<attTH;
}

//setTeamLeader
void TeamLeader::setTeamLeader(double _monBonus, int _reqTH, int _attTH, int _shift, double _hourlyRate, char* _empName, int _empNumber)
{
    monBonus = _monBonus;
    reqTH = _reqTH;
    attTH = _attTH;
    setShift(_shift);
    setHourlyRate(_hourlyRate);
    setEmpName(_empName);
    setEmpNumber(_empNumber);
}

//setMonBonus
void TeamLeader::setMonBonus(double _monBonus)
{
    monBonus = _monBonus;
}
//getMinBonus
double TeamLeader::getMonBonus()
{
    return monBonus;
}

//setReqTH
void TeamLeader::setReqTH(int _reqTH)
{
    reqTH = _reqTH;
}
//getReqTh
int TeamLeader::getReqTH()
{
    return reqTH;
}

//setAttTH
void TeamLeader::setAttTH(int _attTH)
{
    attTH = _attTH;
}
//getAttTH
int TeamLeader::getAttTH()
{
    return attTH;
}