#pragma once

class FeetInches
{

private:
    double feet;
    double inches;
    friend ostream &operator<<(ostream &out, const FeetInches &f);
    friend istream &operator>>(istream &in, FeetInches &f);
    friend FeetInches operator+(FeetInches &f1, FeetInches &f2);

public:
    FeetInches();
    FeetInches(double f, double i);
    void setfeet();
    void setinches();
    double getinches();
    double getfeet();
    bool operator==(FeetInches f);

    FeetInches operator+(FeetInches f);

    FeetInches operator++();

    FeetInches operator++(int);

    operator double();
};