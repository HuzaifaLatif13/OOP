#include"Character.h"

//Overload_constructor
Character::Character(string _name, int _level, int _health)
{
    name = _name;
    level = _level;
    health = _health;
}

//Virtual_attack
int Character::attack()
{
    return 0;
}

//getName
string Character::getName()
{
    return name;
}

//getHealth
int Character::getHealth()
{
    return health;
}

//setHealth
void Character::setHealth(int _health)
{
    health = _health;
}