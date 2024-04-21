#include"Magazine.h"
#include<iostream>
using namespace std;

//Overloaded Constructor
Magazine::Magazine(string _month, int _year, string _title) : Media(_title)
{
    month = _month;
    year = _year;
}

//copy
Magazine::Magazine(Magazine &m) : Media(m.title)
{
    this->month = m.month;
    this->year = m.year;
}

//assignment
Magazine Magazine::operator=(Magazine &m)
{
    this->month = m.month;
    this->year = m.year;
    this->title = m.title;
}

//display
void Magazine::display()
{
    cout<<"\nMedia Title: "<<title<<"\nMagazine Month: "<<month<<"\nMagazine Year: "<<year;
}