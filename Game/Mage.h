#include"Character.h"
#pragma once
#include<string>
using namespace std;

class Mage : public Character
{
private:
    int MStrength;

public:
    Mage(string _name="Null",int _level=0,int _health=0,int _MStrength=0);
    int attack ();
};