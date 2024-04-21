#include"Book.h"
#include<iostream>
using namespace std;

//Overloaded Constructor
Book::Book(string _author, string _ISBN, string _title) : Media(_title)
{
    author = _author;
    ISBN = _ISBN;
}

//copy
Book::Book(Book& b) : Media(b.title)
{
    this->author = b.author;
    this->ISBN = b.ISBN;
}

//assignment
Book Book::operator=(Book &b)
{
    this->author = b.author;
    this->ISBN = b.ISBN;
    this->title = b.title;    
}

//display
void Book::display()
{
    cout<<"\nMedia Title: "<<title<<"\nBook Author: "<<author<<"\nBook ISBN: "<<ISBN;
}