#include<iostream>
#include"FeetInches.cpp"
#include"FeetInches.h"
using namespace std;

int main()
{
    
    int ft,inch;
    FeetInches fi1;//default constructor

    FeetInches fi2;
    cout<<"Enter feet of first object:";
    fi1.setfeet();
    cout<<"Enter inches of first object:";
    fi1.setinches();
    cout<<"Enter feet of second object:";
    fi2.setfeet();
    cout<<"Enter inches of first object:";
    fi2.setinches();
    cout<<"\n";
    if(fi1==fi2)
    {
        cout<<"Equal"<<endl;
    }
    else
    cout<<"Not Equal"<<endl;

    FeetInches fi3;
    fi3=fi1+fi2;
    cout<<"inches"<<endl;
    cout<<fi3.getinches()<<endl;
    cout<<"Feet"<<endl;
    cout<<fi3.getfeet()<<endl;

    FeetInches fi4;
    fi4=++fi3;
    cout<<"Feet"<<endl;
    cout<<fi4.getfeet()<<endl;
    cout<<"inches"<<endl;
    cout<<fi4.getinches()<<endl;

    fi2=fi3++;
    cout<<"Feet"<<endl;
    cout<<fi2.getfeet()<<endl;
    cout<<"inches"<<endl;
    cout<<fi2.getinches()<<endl;

    cout<<"\nAfter Type Casting,the length is:";
    double length;
    length=fi2;
    cout<<length;




    

}