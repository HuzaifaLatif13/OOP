#include"Media.h"
#include<iostream>
using namespace std;

//Overloaded Constructor
Media::Media(string _title)
{
    title = _title;
}

//copy constructor
Media::Media(Media &m)
{
    this->title = m.title;
}

//assignment
Media Media::operator=(Media &m)
{
    this->title = m.title;
}

//display
void Media::display()
{
    cout<<"\nMedia Title: "<<title;
}