#pragma once
#include<string>
using namespace std;

class Character
{
private:
    string name;
    int level;
    int health;

public:
    Character(string _name = "Null" , int _level=0, int _health=0);
    virtual int attack(); 
    string getName();
    int getHealth();
    void setHealth(int _health);
};