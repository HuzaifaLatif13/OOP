#include <iostream>
using namespace std;
class MyString
{
private:
    char *str;
    int length;

public:
    MyString();
    MyString(const char *);
    ~MyString();
    void display();
    const int getlength();
    MyString(const MyString &m);
    MyString operator+(const MyString &) const;
    bool operator==(const MyString &) const;
    bool operator<(const MyString &) const;
    bool operator<=(const MyString &) const;
    const MyString &operator+=(const MyString &);
    void setStr(const char *);
    MyString MyString::operator=(MyString *s);
    MyString operator++();
};
// default constructor
MyString::MyString()
{
    str = new char[1];
    str[0] = '\0';
    length = 0;
}

// overloaded constructor
MyString::MyString(const char *arr)
{
    length = 0;
    int i = 0;
    while (arr[i] != '\0')
    {
        length++;
        i++;
    }
    str = new char[length + 1];
    for (int i = 0; i < length + 1; i++)
    {
        str[i] = arr[i];
    }
}

// destructor
MyString::~MyString()
{
    delete[] str;
}

// display

void MyString::display()
{
    cout << "The string is:";
    cout << str;
}

// getlength
const int MyString::getlength()
{
    length = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        length++;
        i++;
    }

    return length;
}

// copy constructor
MyString::MyString(const MyString &m)
{
    this->str = m.str;
    this->length = m.length;
}
// overload +

MyString MyString::operator+(const MyString &m) const
{
    MyString temp;
    int i = 0;
    while (this->str[i] != '\0')
    {
        temp.str[i] = this->str[i];
        i++;
    }
    temp.str[i] = ' ';
    i++;
    for (int j = 0; m.str[j] != '\0'; j++)
    {
        temp.str[i] = m.str[j];
        i++;
    }
    temp.str[i] = '\0';

    return temp;
}
// overload ==operator

bool MyString::operator==(const MyString &m) const
{
    int i = 0;
    int flag = 0;
    while (this->str[i] != '\0')
    {

        if (this->str != m.str)
        {
            flag = 1;
        }
        i++;
    }
    if (flag == 0)
    {
        return true;
    }
    else
        return false;
}
// overload <
bool MyString::operator<(const MyString &m) const
{
    int i = 0;
    int flag = 0;
    while (this->str[i] != '\0' && m.str[i] != '\0')
    {
        if (this->str[i] == m.str[i])
        {
        }
        else if (this->str > m.str)
        {
            flag = 1;
        }
        i++;
    }
    if (flag == 0)
    {
        return true;
    }
    else
        return false;
}

//<= overload

bool MyString::operator<=(const MyString &m) const
{
    int i = 0;
    int flag = 0;
    while (this->str[i] != '\0' && m.str[i] != '\0')
    {

        if (this->str > m.str)
        {
            flag = 1;
        }
        i++;
    }
    if (flag == 0)
    {
        return true;
    }
    else
        return false;
}

// overloading +=
const MyString &MyString::operator+=(const MyString &m)
{

    int i = 0;
    while (this->str[i] != '\0')
    {
        i++;
    }
    this->str[i] = ' ';
    i++;
    for (int j = 0; m.str[j] != '\0'; j++)
    {
        this->str[i] += m.str[j];
        i++;
    }

    this->str[i] = '\0';

    return *this;
}

// setstr

void MyString::setStr(const char *c)
{
    int i = 0;
    length = 0;
    while (c[i] != '\0')
    {
        length++;
        i++;
    }
    delete[] this->str;
    str = new char[length + 1];
    i = 0;
    while (c[i] != '\0')
    {
        this->str[i] = c[i];
        i++;
    }
}

// prefix operator
MyString MyString::operator++()
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
    return *this;
}

MyString MyString::operator=(MyString *s)
{
    this->str = s->str;
    this->length = s->length;
    return *this;
}
int main()
{
    MyString s1;
    MyString s2("OOP is fun!!");

    char name[15] = "Pakistan";
    MyString s3(name);

    MyString ms1("One");
    MyString ms2("Two");
    MyString ms3("Three");
    ms1 + ms2 + ms3;

    MyString S1("abc");
    MyString S2("ABC");
    MyString S3("az");
    MyString S4("abc");

    cout << (S1 == S2);
    cout << (S4 == S1);
    cout << (S4 == S4);

    cout << (S1 < S2);
    cout << (S2 < S1);

    cout << (S1 < S3);
    cout << (S1 <= S3);
    cout << (S1 <= S4);
    cout << (S2 <= S2);

    cout << (S3 < S1);
    cout << (S3 <= S1);
    cout << (S3 <= S3);

    MyString Ms1("One");
    MyString Ms2("Two");
    MyString Ms3("Three");
    Ms1 += Ms2 += Ms3;

    Ms1.display();
    Ms2.display();
    Ms3.display();

    // setstring

    MyString MS1("Hello");
    MS1.display();

    MS1.setStr("Welcome to oop");
    MS1.display();
}