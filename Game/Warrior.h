#pragma once
#include "character.h"
#include<string>
using namespace std;

class Warrior : public Character
{
private:
    int WStrength;

public:
    Warrior(string _name="Null",int _level=0,int _health=0,int _WStrength=0);
    int attack ();
};