#include <iostream>
using namespace std;
class IntArray
{
private:
    int *arr;
    int arraySize;
    friend ostream &operator<<(ostream &out, const IntArray &);

public:
    IntArray(int);
    IntArray(const IntArray &);
    ~IntArray();
    int size() const;
    int &operator[](const int);
    const IntArray &operator=(const IntArray &);
    IntArray operator+(int) const;
    void setArray();
    void storeData(const int *data, int n);
    void operator!() const;
};
IntArray::IntArray(int size)
{
    this->arraySize = size;
    arr = new int[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        arr[i] = 0;
    }
}
void IntArray::setArray()
{
    cout << "\nEnter the elements of an array: " << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cin >> arr[i];
    }
}
IntArray::IntArray(const IntArray &a)
{
    cout << "\nCopy constructor called.";
    this->arraySize = a.arraySize;
    this->arr = new int[this->arraySize];
    for (int i = 0; i < a.arraySize; i++)
    {
        this->arr[i] = a.arr[i];
    }
}
IntArray::~IntArray()
{
    delete[] arr;
}
int IntArray::size() const
{
    return arraySize;
}
int &IntArray::operator[](const int ind)
{
    return arr[ind];
}
// overloading assignment operator
const IntArray &IntArray::operator=(const IntArray &a)
{
    cout << "\nAssignment operator called.";
    this->arraySize = a.arraySize;
    this->arr = new int[this->arraySize];
    for (int i = 0; i < this->arraySize; i++)
    {
        this->arr[i] = a.arr[i];
    }
}
// add an integer value to all elements of an array
IntArray IntArray::operator+(int a) const
{
    for (int i = 0; i < this->arraySize; i++)
    {
        arr[i] += a;
    }
    return *this;
}
// extraction operator
ostream &operator<<(ostream &out, const IntArray &a)
{
    cout << "\nThe array elements are: ";
    for (int i = 0; i < a.arraySize; i++)
    {
        cout << a.arr[i] << " ";
    }
    return out;
}
void IntArray::storeData(const int *data, int n)
{
    if (n != arraySize)
    {
        this->arraySize = n;
        delete[] arr;
        arr = new int[this->arraySize];
        for (int i = 0; i < this->arraySize; i++)
        {
            this->arr[i] = data[i];
        }
    }
    else
    {
        for (int i = 0; i < this->arraySize; i++)
        {
            this->arr[i] = data[i];
        }
    }
}
void IntArray::operator!() const
{
    cout << "\nThe elements of array in reverse order is: ";
    for (int i = arraySize - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int size;
    IntArray a(5);
    cout << a;
    a.setArray();
    cout << a;
    IntArray a1 = a;
    cout << a1;
    IntArray a2(10);
    a2 = a1;
    cout << a2;
    a + 5;
    cout << a;
    cout << "\nEnter the size of an array: ";
    cin >> size;
    while (size < 0)
    {
        cout << "\nInvalid size. Enter again: ";
        cin >> size;
    }
    int *arr = new int[size];
    cout << "\nEnter the elements of an array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    a1.storeData(arr, size);
    cout << a1;
    //<...............................>
    IntArray a1(5);
    IntArray a2(2);
    cout << a1; // should display: 0 0 0 0 0
    cout << a2; // should display: 0 0
    int arr[3] = {10, 20, 30};
    a1.storeData(arr, 3);
    a2.storeData(arr, 3);
    cout << a1; // should display: 10 20 30
    cout << a2;
    !a2;

    return 0;
}