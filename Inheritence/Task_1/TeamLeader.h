#pragma once
#include"ProductionWorker.h"

class TeamLeader : public ProductionWorker
{
private:
    double monBonus;
    int reqTH;
    int attTH;
public:
    //overload
    TeamLeader(double _monBonus, int _reqTH, int _attTH, int _shift, double _hourlyRate, char* _empName, int _empNumber);
    //copy
    TeamLeader(TeamLeader &tl);
    //assignment
    TeamLeader operator=(TeamLeader &tl);
    //display
    void TLdisplay();
    //setTeamLeader
    void setTeamLeader(double _monBonus, int _reqTH, int _attTH, int _shift, double _hourlyRate, char* _empName, int _empNumber);
    //setter & getter
    void setMonBonus(double _monBonus);
    double getMonBonus();
    void setReqTH(int _reqTH);
    int getReqTH();
    void setAttTH(int _attTH);
    int getAttTH();
};