#include"Character.h"
#include"Warrior.h"
#include"Mage.h"
#include"Rogue.h"

#include<iostream>
#include<stdlib.h>
using namespace std;
//inputFunction
void input(string&, int&, int&, int&);
//battelFunction
void battle(Character*, Character*);

int main()
{
    string _name;
    int _level, _health, _strength;
    
    system("cls");
    int ch;
    cout<<"\n\t<---Game Menu--->"<<endl;
    cout<<"\n\t1. Start Game\n\t2. Exit Game\n\nEnter choice(1-2): ";
    cin>>ch;
    while (ch!=1 && ch!=2)    //validation
    {
        cout<<"\nWrong Choice! Enter Choice Again(1-2): ";
        cin>>ch;
    }

    //input
    while (ch!=2 || ch==0)
    {
        Character *c1, *c2;
        system("cls");
        //first
        cout<<"\n\tChoose First character!";
        input(_name, _level, _health, _strength);
        if (_name=="Warrior")
        {
            c1 = new Warrior(_name, _level, _health, _strength);
        }
        else if (_name=="Mage")
        {
            c1 = new Mage(_name, _level, _health, _strength);
        }
        else if (_name=="Rogue")
        {
            c1 = new Rogue(_name, _level, _health, _strength);
        }
        cout<<"\n<---------------------------------------------------------->"<<endl;
        //second
        cout<<"\n\tChoose Second character!";
        input(_name, _level, _health, _strength); 
        if (_name=="Warrior")
        {
            c2 = new Warrior(_name, _level, _health, _strength);
        }
        else if (_name=="Mage")
        {
            c2 = new Mage(_name, _level, _health, _strength);
        }
        else if (_name=="Rogue")
        {
            c2 = new Rogue(_name, _level, _health, _strength);
        }       

        //battling
        battle(c1,c2);

        
        cout<<"\n\n\tPlay Again?\n\tEnter '0' to play again!\n\tEnter '2' to Exit!\n\tEnter(0 || 2):";
        cin>>ch;
        while (ch!=0 && ch!=2)    //validation
        {  
            cout<<"\n\tWrong Choice! Enter Choice Again(1-2): ";
            cin>>ch;
        }

        //delete
        delete c1;
        delete c2;
    }

    cout<<"\n\n\tExit Successfully!"<<endl;

    return 0;
}

//input
void input(string& _name, int& _level, int& _health, int& _strength)
{
    int ch;
    cout<<"\n\t1. Warrior  ~Attack*4\n\t2. Mage     ~Attack*5\n\t3. Rogue    ~Attack*6\n\nEnter Character(1-3): ";
    cin>>ch;
    while (ch<1 || ch>3)    //validation
    {
        cout<<"\nWrong Choice! Enter Choice Again(1-3): ";
        cin>>ch;
    }
    if (ch==1)
    {
        _name = "Warrior";
    }
    else if (ch==2)
    {
        _name = "Mage";
    }
    else if (ch==3)
    {
        _name = "Rogue";
    }

    cout<<"\n<---"<<_name<<" Info--->";
    cout<<"\nEnter Level: ";
    cin>>_level;
    cout<<"\nEnter Health(0-100): ";
    cin>>_health;
    while (_health<0 || _health>100)    //validation
    {
        cout<<"\nWrong Value! Enter Health again(0-100): ";
        cin>>_health;
    }
    cout<<"\nEnter Strength: ";
    cin>>_strength;

}

//Battle_define
void battle(Character* c1, Character* c2)
{
    //damageVariables
    int damage1,damage2;

    //Battling
    while(c1->getHealth()>0 && c2->getHealth()>0 )
    {
        damage1=c1->attack();
        c2->setHealth( ((c2->getHealth()) - damage1) );

        damage2=c2->attack();
        c1->setHealth( ((c1->getHealth()) - damage2) );

    }

    //Results
    cout<<"\n\n<------------------------WIN------------------------>";
    if(c1->getHealth() < c2-> getHealth())
    {
        cout<<"\n\tCharacter 2 [ "<< c2->getName() <<" ] is winner!!\n";
    }
    else 
    {
        cout<<"\n\tCharacter 1 [ " << c1->getName() <<" ] is winner!!\n"; 
    }
    cout<<"<------------------------WIN------------------------>";
}