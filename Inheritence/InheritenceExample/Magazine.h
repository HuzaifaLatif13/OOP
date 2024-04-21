#pragma once
#include"Media.h"
#include<string>
using namespace std;

class Magazine : public Media
{
private:
    string month;
    int year;
public:
    Magazine(string _month, int _year, string _title);
    Magazine(Magazine &m);
    Magazine operator=(Magazine &m);
    void display();
};