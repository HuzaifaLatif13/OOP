#include"Warrior.h"

//overload_constructor
Warrior::Warrior(string _name,int _level,int _health,int _WStrength) : Character(_name,_level,_health)
{
    WStrength = _WStrength;
}

//Attack
int Warrior::attack()
{
    return (WStrength * 4); 
}