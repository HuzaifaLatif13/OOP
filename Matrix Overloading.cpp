#include <iostream>
using namespace std;
class Matrix
{
private:
    int **p;
    int rows;
    int columns;
    friend Matrix operator+(Matrix &m1, Matrix &m2);
    friend void operator-=(Matrix &m1, Matrix &m2);
    friend Matrix operator*(Matrix &m1, Matrix &m2);
    friend int operator*(int num, Matrix &m1);
    friend Matrix operator*(Matrix &m1, int num);
    friend void operator*(int *arr, Matrix &m1);
    friend Matrix operator*(Matrix &m1, int arr[]);
    friend void operator/(Matrix &m1, int num);
    friend Matrix operator^(Matrix &m1, int pow);
    friend bool operator<(Matrix &m1, Matrix &m2);
    friend bool operator>(Matrix &m1, Matrix &m2);
    friend bool operator==(Matrix &m1, Matrix &m2);

public:
    Matrix();
    ~Matrix();
    void setter();
    void display();
    void operator=(const Matrix &m1);
};

// default constructor
Matrix::Matrix()
{
    this->columns = 3;
    this->rows = 3;
    p = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        p[i] = new int[columns];
    }

    // initialize with zero
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            p[i][j] = 0;
        }
    }
}

// destructor
Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] p[i];
    }
    delete[] p;
}

// setter
void Matrix::setter()
{
    cout << "Enter elements of matrix: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cin >> p[i][j];
        }
        cout << "\n";
    }
}
// display
void Matrix::display()
{

    cout << "\n The matrix is: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << p[i][j];
            cout << " ";
        }
        cout << endl;
    }
}

// assignment
void Matrix::operator=(const Matrix &m1)
{
    for (int i = 0; i < m1.rows; i++)
    {
        for (int j = 0; j < m1.columns; j++)
        {
            this->p[i][j] = m1.p[i][j];
        }
    }
}

// + overloading
Matrix operator+(Matrix &m1, Matrix &m2)
{
    Matrix temp;
    for (int i = 0; i < m1.rows; i++)
    {
        for (int j = 0; j < m1.columns; j++)
        {
            temp.p[i][j] = m1.p[i][j] + m2.p[i][j];
        }
    }
    return temp;
}

// - overloading
void operator-=(Matrix &m1, Matrix &m2)
{
    for (int i = 0; i < m1.rows; i++)
    {
        for (int j = 0; j < m1.columns; j++)
        {
            m1.p[i][j] -= m2.p[i][j];
        }
    }
}

// multiplication

Matrix operator*(Matrix &m1, Matrix &m2)
{
    Matrix temp;
    for (int i = 0; i < m1.rows; i++)
    {
        for (int j = 0; j < m1.columns; j++)
        {
            for (int k = 0; k < m1.columns; k++)
            {
                temp.p[i][j] += m1.p[i][k] * m2.p[k][j];
            }
        }
    }
    return temp;
}
//* martrix by a number
int operator*(int num, Matrix &m1)
{
    int sum = 0;
    for (int i = 0; i < m1.columns; i++)
    {
        for (int j = 0; j < m1.columns; j++)
        {
            sum = sum + m1.p[i][j];
        }
    }
    sum = sum * num;
    return sum;
}

// num*matrix
Matrix operator*(Matrix &m1, int num)
{
    Matrix temp;
    for (int i = 0; i < m1.rows; i++)
    {
        for (int j = 0; j < m1.columns; j++)
        {
            temp.p[i][j] = num * m1.p[i][j];
        }
    }
    return temp;
}

// v ector * matrix

void operator*(int *arr, Matrix &m1)
{
    int temp[3] = {0};

    for (int i = 0; i < m1.rows; i++)
    {
        for (int j = 0; j < m1.columns; j++)
        {
            temp[i] += arr[j] * m1.p[j][i];
        }
    }
    cout << "\n { 1,2,3 } * M: " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << temp[i];
        cout << " ";
    }
    cout << endl;
}

// Matrix * vex

Matrix operator*(Matrix &m1, int arr[])
{
    Matrix temp;
    int sum = 0;
    for (int i = 0; i < m1.rows; i++)
    {
        sum = sum + arr[i];
    }
    for (int i = 0; i < m1.rows; i++)
    {
        for (int j = 0; j < m1.columns; j++)
        {
            temp.p[i][j] = m1.p[i][j] * sum;
        }
    }
    return temp;
}

void operator/(Matrix &m1, int num)
{
    float p[3][3];
    for (int i = 0; i < m1.rows; i++)
    {
        for (int j = 0; j < m1.columns; j++)
        {
            p[i][j] = m1.p[i][j] / (num);
        }
    }
    cout << "\nAfter division the matrix is: " << endl;
    for (int i = 0; i < m1.rows; i++)
    {
        for (int j = 0; j < m1.columns; j++)
        {
            cout << p[i][j];
            cout << " ";
        }
        cout << endl;
    }
}

Matrix operator^(Matrix &m1, int pow)
{
    Matrix temp;
    if (pow == 0)
    {
        for (int i = 0; i < m1.rows; i++)
        {
            for (int j = 0; j < m1.columns; j++)
            {
                temp.p[i][j] = 1;
            }
        }
    }
    else if (pow == 1)
    {
        for (int i = 0; i < m1.rows; i++)
        {
            for (int j = 0; j < m1.columns; j++)
            {
                temp.p[i][j] = m1.p[i][j];
            }
        }
    }
    else
    {
        temp = m1 * m1;
        for (int i = 2; i < pow; i++)
        {
            temp = temp * m1;
        }
    }

    return temp;
}

//< overload

bool operator<(Matrix &m1, Matrix &m2)
{
    for (int i = 0; i < m1.rows; i++)
    {
        for (int j = 0; j < m1.columns; j++)
        {
            if (m1.p[i][j] < m2.p[i][j])
            {
                return true;
            }
        }
    }
    return false;
}

// > overload

bool operator>(Matrix &m1, Matrix &m2)
{
    for (int i = 0; i < m1.rows; i++)
    {
        for (int j = 0; j < m1.columns; j++)
        {
            if (m1.p[i][j] < m2.p[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

// == overload

bool operator==(Matrix &m1, Matrix &m2)
{
    for (int i = 0; i < m1.rows; i++)
    {
        for (int j = 0; j < m1.columns; j++)
        {
            if (m1.p[i][j] != m2.p[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n, power;
    Matrix m;
    m.setter();
    m.display();
    Matrix m1;
    m1.setter();
    m1.display();
    Matrix m2 = m + m1;
    m2.display();
    m2 -= m1;
    m2.display();
    Matrix m3 = m1 * m2;
    m3.display();

    cout << "\n<---------------------------------------------------------->" << endl;
    cout << "Enter a number: ";
    cin >> n;
    m.display();
    cout << "\nN * M: " << (n * m) << endl;

    cout << "\n<---------------------------------------------------------->" << endl;
    m1.display();
    Matrix m4 = m1 * n;
    cout << "\n M1 * N: ";
    m4.display();
    cout << "\n<---------------------------------------------------------->" << endl;
    m.display();
    int arr[3] = {1, 2, 3};
    arr *m;
    cout << "\n<---------------------------------------------------------->" << endl;
    m1.display();
    cout << "M1 * arr: " << endl;

    Matrix m5 = m1 * arr;
    m5.display();
    cout << "\n<---------------------------------------------------------->" << endl;
    m1.display();
    cout << "M1 / n: " << endl;
    m1 / n;

    cout << "\n<---------------------------------------------------------->" << endl;
    m1.display();
    cout << "M1 ^ pow: " << endl;
    cout << "Enter power of the Matrix : ";
    cin >> power;
    Matrix m7 = m1 ^ power;
    m7.display();
    cout << "\n<---------------------------------------------------------->" << endl;
    m1.display();
    m.display();
    cout << "M1 < M: " << (m1 < m) << endl;
    cout << "\n<---------------------------------------------------------->" << endl;
    m1.display();
    m.display();
    cout << "M1 > M: " << (m1 > m) << endl;
    cout << "\n<---------------------------------------------------------->" << endl;
    m1.display();
    m.display();
    cout << "M1 == M: " << (m1 == m) << endl;

    return 0;
}