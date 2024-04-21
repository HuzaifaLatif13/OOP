#pragma once

#include<string>
using namespace std;

class Media
{
protected:
    string title;

public:
    Media(string _title);
    Media(Media &m);
    Media operator = (Media &m);
    virtual void display();
    
};
