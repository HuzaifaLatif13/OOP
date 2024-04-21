#include <iostream>
#include <cstring>
using namespace std;
class Mystring
{
private:
    char *str;
    int length;

public:
    // default constructor
    Mystring()
    {
        this->str = nullptr;
        this->length = 0;
    }
    // overloaded constructor
    Mystring(const char *str)
    {
        length = 0;
        for (int i = 0; str[i] != '\0'; i++)
        {
            length++;
        }
        this->str = new char[length];
        for (int i = 0; i < length; i++)
        {
            this->str[i] = str[i];
        }
        this->str[length] = '\0';
    }
    // destructor
    ~Mystring()
    {
        delete[] str;
    }
    // display
    void display()
    {
        cout << "\nThe string is: " << this->str;
        cout << "\nThe lenght is: " << this->length;
    }
    // return the length of string
    int getLength()
    {
        return length;
    }
    // copy constructor
    Mystring(Mystring &m)
    {
        cout << "\nIts copy constructor.";
        this->length = m.length;
        str = new char[length + 1];
        strcpy(this->str, m.str);
    }
    // overloading assignment operator
    const Mystring &operator=(const Mystring &m)
    {
        cout << "\nAssignment operator overload.";
        this->length = m.length;
        str = new char[length + 1];
        strcpy(this->str, m.str);
        return *this;
    }
    // overloading + operator
    Mystring operator+(const Mystring &m) const
    {
        int newlength = this->length + m.length;
        char *newString = new char[newlength];
        for (int i = 0; i < this->length; i++)
        {
            newString[i] = this->str[i];
        }
        for (int i = 0; i < m.length; i++)
        {
            newString[this->length + i] = m.str[i];
        }
        newString[newlength] = '\0';
        Mystring m1(newString);
        delete[] newString;
        return m1;
    }
    // equal to operator overloading
    bool operator==(const Mystring &m)
    {
        if (this->length != m.length)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    // overloading < operator
    bool operator<(const Mystring &m)
    {
        if (this->length >= m.length)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    // overloading += operator
    const Mystring &operator+=(const Mystring &m)
    {
        cout << "\nLets overload += operator." << endl;
        int newlength = this->length + m.length + 1;
        char *newstring = new char[newlength];
        for (int i = 0; i < this->length; i++)
        {
            newstring[i] = this->str[i];
        }
        newstring[this->length] = ' ';

        for (int i = 0; i < m.length; i++)
        {
            newstring[this->length + 1 + i] = m.str[i];
        }
        this->length = newlength;
        delete[] this->str;
        this->str = new char[this->length];
        for (int i = 0; i < this->length; i++)
        {
            this->str[i] = newstring[i];
        }
        delete[] newstring;
        return *this;
    }
    // set string
    void setStr(const char *s)
    {
        delete[] str;
        length = 0;
        for (int i = 0; s[i] != '\0'; i++)
        {
            length++;
        }
        this->str = new char[length];
        for (int i = 0; i < length; i++)
        {
            this->str[i] = s[i];
        }
    }
    // overloading <= funstion
    bool operator<=(const Mystring &m)
    {
        cout << "\nLets overload <= operator." << endl;
        if (this->length > m.length)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    // overloading >= funstion
    bool operator>=(const Mystring &m)
    {
        cout << "\nLets overload >= operator." << endl;
        if (this->length < m.length)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    // overloading > funstion
    bool operator>(const Mystring &m)
    {
        cout << "\nLets overload > operator." << endl;
        if (this->length <= m.length)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    // overloading != funstion
    bool operator!=(const Mystring &m)
    {
        cout << "\nLets overload != operator." << endl;
        if (this->length == m.length)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
int main()
{
    Mystring m("OOP IS FUN!!");
    m.display();
    cout << "\nThe length of the string is: " << m.getLength();
    cout << "\n<.......................>" << endl;
    cout << "\nChecking functioning of + operator." << endl;
    Mystring m1("I am Husna Sarwar");
    Mystring m3;
    m3 = m + m1;
    m3.display();
    if (m3 < m1)
    {
        cout << "\ntrue";
    }
    else
    {
        cout << "\nFalse";
    }
    Mystring m4("OOP IS FUN!!");
    if (m4 == m)
    {
        cout << "\ntrue";
    }
    else
    {
        cout << "\nFalse";
    }
    Mystring m5("Hey! Its me Husna");
    m5 += m;
    m5.display();
    char str[30];
    cout << "\nEnter string.";
    cin.getline(str, 30);

    m5.setStr(str);

    m5.display();
    if (m1 <= m)
    {
        cout << "\nTrue.";
    }
    else
    {
        cout << "\nFalse.";
    }
    if (m4 >= m1)
    {
        cout << "\nTrue";
    }
    else
    {
        cout << "\nFalse";
    }
    if (m3 > m1)
    {
        cout << "\nTrue";
    }
    else
    {
        cout << "\nFalse";
    }
    if (m4 != m3)
    {
        cout << "\nTrue";
    }
    else
    {
        cout << "\nFalse";
    }

    return 0;
}
