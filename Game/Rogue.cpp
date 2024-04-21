#include"Rogue.h"

//overload Constructor
Rogue::Rogue(string _name,int _level,int _health,int _RStrength) : Character(_name,_level,_health)
{
    RStrength = _RStrength;
}

//attack
int Rogue::attack()
{
    return (RStrength * 6);
}