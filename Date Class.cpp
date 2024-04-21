#include <iostream>
using namespace std;
class Date
{
private:
    int day, month, year;

public:
    Date(int day = 0, int month = 0, int year = 0)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void setDay()
    {
        cout << "\nEnter Day: ";
        cin >> day;
        while (day < 0 || day > 31)
        {
            cout << "\nInvalid day.Enter again: ";
            cin >> day;
        }
        if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            while (day > 30)
            {
                cout << "\nInvalid day.This month has 30 days only. Enter again: ";
                cin >> day;
            }
        }
        if (month == 2)
        {
            if (year % 4 == 0)
            {
                while (day > 29)
                {
                    cout << "\nInvalid day.Its a leap Feb. Enter again: ";
                    cin >> day;
                }
            }
            else
            {
                while (day > 28)
                {
                    cout << "\nInvalid day.Its Feb. Enter again: ";
                    cin >> day;
                }
            }
        }
    }
    void setMonth()
    {
        cout << "\nEnter Month: ";
        cin >> month;
        while (month < 0 || month > 12)
        {
            cout << "\nInvalid month.Enter again: ";
            cin >> month;
        }
    }
    void setYear()
    {
        cout << "\nEnter Year: ";
        cin >> year;
        while (year < 1000 || year > 2023)
        {
            cout << "\nInvalid year.Enter again: ";
            cin >> year;
        }
    }
    int getDay()
    {
        return day;
    }
    int getMonth()
    {
        return month;
    }
    int getYear()
    {
        return year;
    }
    void display()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};
int main()
{
    int size;
    Date d(8, 23, 2023);
    d.display();
    d.setYear();
    d.setMonth();
    d.setDay();
    d.display();
    cout << "\nWithout dynamic allocation!" << endl;
    Date d1[5] = {Date(21, 4, 1838), Date(9, 11, 1877), Date(14, 7, 1947), Date(11, 8, 1948), Date(25, 12, 1876)};
    for (int i = 0; i < 5; i++)
    {
        d1[i].display();
    }
    cout << "\nBy Allocationg memory." << endl;
    cout << "\nEnter The size of structure: ";
    cin >> size;
    while (size < 0)
    {
        cout << "\nInvalid size.Enter again: ";
        cin >> size;
    }
    Date *d2 = new Date[size];
    for (int i = 0; i < size; i++)
    {
        d2[i].setYear();
        d2[i].setMonth();
        d2[i].setDay();
    }
    for (int i = 0; i < size; i++)
    {
        d2[i].display();
    }
    delete[] d2;
    return 0;
}