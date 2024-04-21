#pragma once
#include"Media.h"
#include<string>
using namespace std;

class Book : public Media
{
private:
    string author;
    string ISBN;
public:
    Book(string _author, string _ISBN, string _title);
    Book(Book &b);
    Book operator= (Book&b);
    void display();
};
