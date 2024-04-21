#include"Matrix.cpp"
#include<iostream>
using namespace std;

int main()
{
    int size;
    cout<<"\nEnter Matrix size: ";
    cin>>size;
    Matrix m(size);
    m.setMatrix();
    m.display();
    cout << "\n----------------------------------------------\n";

    int row, column,value;
    cout<<"\n!----Get Value----!\n";
    cout<<"\nEnter row: ";
    cin>>row;
    while (row<0 || row>=size)
    {
        cout<<"\nError Input\nEnter row: ";
        cin>>row;
    }
    cout<<"\nEnter column: ";
    cin>>column;
    while (column<0 || column>=size)
    {
        cout<<"\nError Input\nEnter column: ";
        cin>>column;
    }
    cout<<"\nValue at ["<<row<<"]["<<column<<"]: "<< m.getElement(row,column);
    cout << "\n----------------------------------------------\n";

    cout<<"\n!----Set Value----!\n";
    cout<<"\nEnter row: ";
    cin>>row;
    while (row<0 || row>=size)
    {
        cout<<"\nError Input\nEnter row: ";
        cin>>row;
    }
    cout<<"\nEnter column: ";
    cin>>column;
    while (column<0 || column>=size)
    {
        cout<<"\nError Input\nEnter column: ";
        cin>>column;
    }
    cout << "\nEnter value to be added: ";
    cin>>value;
    m.setElement(row,column,value);
    m.display();
    cout << "\n----------------------------------------------\n";

    cout<<"\n!----90* Rotation----!\n";
    m.rotate();
    m.display();
    cout << "\n----------------------------------------------\n";

    cout<<"\n!----Multiplication----!\n";
    Matrix m1(size);
    m1.setMatrix();
    m1.display();

    Matrix temp(size);
    temp = m*m1;
    temp.display();
    cout << "\n----------------------------------------------\n";

    cout<<"\n!----Determinant----!\n";
    cout << "\nDeterminant of Matrix 1 is: "<<m.determinant();

    cout << endl;
    return 0;
}