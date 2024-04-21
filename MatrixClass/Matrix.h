#pragma once
#include<iostream>
using namespace std;

class Matrix
{
private:
    int size;
    int **array;
    
public:
    Matrix(int _size=2);
    ~Matrix();
    void setMatrix();
    void display();
    int getElement(int row,int column);
    void setElement(int row,int column, int value);
    void rotate();
    Matrix operator*(Matrix& m);
    void operator = (Matrix m); 
    int determinant();
};