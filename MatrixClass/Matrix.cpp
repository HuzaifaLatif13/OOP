#include"Matrix.h"

//constructor
Matrix::Matrix(int _size)
{
    this->size = _size;
    array = new int*[size];
    for (int i=0; i<size; i++)
    {
        array[i] = new int[size];
    }
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            array[i][j] = 0;
        }   
    }
}

//Destructor
Matrix::~Matrix()
{
    for (int i=0; i<size; i++)
    {
        delete[] array[i];
    }
    delete[] array;
}

//Input
void Matrix::setMatrix()
{
    cout << "\nEnter elements of array:\n";
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            cin >> array[i][j];
        }
        cout << endl;
    }
}

//Output
void Matrix::display()
{
    cout << "\nThe elements of array:\n";
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}

//GetElement
int Matrix::getElement(int row, int column)
{
    return array[row][column];
}

//setElement
void Matrix::setElement(int row, int column, int value)
{
    array[row][column] = value;
}

//assignment overload
void Matrix::operator=(Matrix m)
{
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            this->array[i][j] = m.array[i][j];
        }
    }
}

//rotate
void Matrix::rotate()
{
    //tempMatrix
    int** temp;
    temp = new int*[size];
    for (int i=0; i<size ; i++)
    {
        temp[i] = new int[size];
    }
    //setting value in temp
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            temp[i][j] = array[i][j];
        }
    }

    //Taking Transpose
    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
        {
            array[i][j] = temp[j][i];
        }
    }

    //rotating
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size/2; j++)
        {
            int t = array[i][j];
            array[i][j] = array[i][size-1-j];
            array[i][size-1-j] = t;
        }
    }

    //deallocating Temp
    for (int i=0; i<size; i++)
    {
        delete[] temp[i];
    }
    delete[] temp;
}

//product
Matrix Matrix::operator*(Matrix& m)
{
    //tempMatrix
    Matrix temp(size);
    //product
	for (int i = 0; i<size; i++)
	{
		for (int j = 0; j<size; j++)
		{
			for (int k = 0; k<size; k++)
			{
				temp.array[i][j] += this->array[i][k] * m.array[k][j];
			}
		}
	}
    return temp;
}

//derterminant
int Matrix::determinant()
{
    return (array[0][0]*array[1][1] - array[0][1]*array[1][0]);
}