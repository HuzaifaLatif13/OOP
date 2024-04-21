#include"Character.h"
#pragma once
#include<string>
using namespace std;

class Rogue : public Character
{
private:
    int RStrength;

public:
    Rogue(string _name="Null",int _level=0,int _health=0,int _RStrength=0);
    int attack ();
};