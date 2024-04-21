#include"Mage.h"

//overloadConstructor
Mage::Mage(string _name,int _level,int _health,int _MStrength) : Character(_name,_level,_health)
{
    MStrength = _MStrength;
}

//Attack
int Mage::attack()
{
    return (MStrength * 5);
}