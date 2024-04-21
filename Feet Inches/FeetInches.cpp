#include "FeetInches.h"
#include <iostream>
using namespace std;

// default constructor
FeetInches::FeetInches()
{
    feet = 0.0;
    inches = 0.0;
}

// parameterized constructor
FeetInches::FeetInches(double f, double i)
{
    this->feet = f;
    this->inches = i;
    if (inches > 12)
    {
        int n = inches;
        inches = (n % 12);
        feet = feet + (n / 12);
    }
}

// setter

void FeetInches::setfeet()
{
    cin >> feet;
}
void FeetInches::setinches()
{
    cin >> inches;
    if (inches > 12)
    {
        int n = inches;
        inches = (n % 12);
        feet = feet + (n / 12);
    }
}
// getter

double FeetInches::getinches()
{
    return inches;
}
double FeetInches::getfeet()
{
    return feet;
}

// overloading comperaison == for

bool FeetInches::operator==(FeetInches f)
{
    int flag = 0;
    if (f.feet != feet && f.inches != inches)
    {
        flag = 1;
    }
    if (flag == 0)

        return true;
    else
        return false;
}

// overloading + operator

FeetInches FeetInches::operator+(FeetInches f)
{
    FeetInches temp;

    temp.feet = this->feet + f.feet;
    temp.inches = this->inches + f.inches;
    if (temp.inches > 12)
    {
        int n = temp.inches;
        temp.inches = (n % 12);
        feet = feet + (n / 12);
    }
    return temp;
}

// overloading ++operator

FeetInches FeetInches::operator++()
{
    ++this->feet;
    ++this->inches;
    if (inches > 12)
    {
        int n = inches;
        inches = (n % 12);
        feet = feet + (n / 12);
    }

    return *this;
}

FeetInches FeetInches::operator++(int)
{
    this->feet++;
    this->inches++;
    if (inches > 12)
    {
        int n = inches;
        inches = (n % 12);
        feet = feet + (n / 12);
    }

    return *this;
}

// type casting

FeetInches::operator double()
{
    double length;
    length = this->feet + (this->inches / 12);
    return length;
}

istream &operator>>(istream &in, FeetInches &f)
{
    cout << "Enter feet: ";
    cin >> f.feet;
    cout << "Enter inches: ";
    cin >> f.inches;
    return in;
}
ostream &operator<<(ostream &out, const FeetInches &f)
{
    cout << "\nThe feets are: " << f.feet << "\nThe inches are: " << f.inches << endl;
}

FeetInches operator+(FeetInches &f1, FeetInches &f2)
{
    FeetInches temp;
    temp.feet = f1.feet + f2.feet;
    temp.inches = f1.inches + f2.inches;
    if (temp.inches >= 12)
    {
        int inch = temp.inches;
        temp.feet = temp.feet + inch / 12;
        temp.inches = inch % 12;
    }
    return temp;
}