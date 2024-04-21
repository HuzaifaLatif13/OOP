#include"Media.h"
#include"Book.h"
#include"Magazine.h"

#include"Media.cpp"
#include"Book.cpp"
#include"Magazine.cpp"

#include<iostream>
using namespace std;

//book
void inputBook(string &_author, string &_ISBN, string &_title)
{
    cout<<"\nEnter Book Data!!!!!\n";
    cout<<"\nEnter Book title: ";
    getline(cin, _title);
    cout<<"\nEnter Book Author: ";
    getline(cin, _author);
    cout<<"\nEnter Book ISBN: ";
    getline(cin, _ISBN);
}

//magazine
void inputMagazine(string &_month, int &_year, string &_title)
{
    cout<<"\nEnter Magazine Data!!!!!\n";
    cout<<"\nEnter Magazine title: ";
    getline(cin, _title);
    cout<<"\nEnter Magazine month: ";
    getline(cin, _month);
    cout<<"\nEnter Magazine Year: ";
    cin>>_year;
}

int main()
{
    //objects
    Book b("Gaddis", "820", "Starting Out with C++");
    Magazine m ("March", 2023, "SD");

    //display
    cout<<"\n\n<---Book Data--->";
    b.display();
    cout<<"\n\n<---Magazine Data--->";
    m.display();

    //media *
    Media *m1, *m2;
    //variables
    string _title, _author, _ISBN, _month;
    int _year;

    //input
    inputBook(_author, _ISBN, _title);
    //allocation
    m1 = new Book(_author, _ISBN, _title);

    inputMagazine(_month, _year, _title);
    //allocation
    m2 = new Magazine(_month, _year, _title);

    //display
    cout<<"\n\n<---Book Data--->";
    m1->display();
    cout<<"\n\n<---Magazine Data--->";
    m2->display();
    
    
    //deallocation
    delete m1;
    delete m2;
    cout<<"\n\nObjects Destroyed!!!\n";

    int n, ch;
    cout<<"\nHow many Meadia you want to enter: ";
    cin>>n;
    Media **mArray = new Media*[n];
    for (int i=0; i<n ; i++)
    {
        cout<<"\n<--- Choices --->\n1. Book\n2. Magazine\nEnter your choice(1-2): ";
        cin>>ch;
        while (ch!= 1 && ch!=2) //validation
        {
            cout<<"\nWrong choice enter.\nEnter again(1-2): ";
            cin>>ch;
        }

        switch (ch)
        {
        case 1:
            {
                //input
                cin.ignore();
                inputBook(_author, _ISBN, _title);
                //allocation
                mArray[i] = new Book(_author, _ISBN, _title);
            }
            break;
        case 2:
            {
                cin.ignore();
                inputMagazine(_month, _year, _title);
                //allocation
                mArray[i] = new Magazine(_month, _year, _title);
            }
            break;
        }        
    }
    for (int i=0; i<n; i++)
    {
        cout<<"\n<---Data #"<<i<<" --->\n";
        mArray[i]->display();
    }
    
    //deallocation
    delete[] mArray;
    cout<<"\n\nArray Destroyed!!!\n";

    Book b1 = b;
    b1.display();

    Magazine mag("Null", 0, "Null");
    mag = m;
    mag.display();
    
    
    return 0;
}