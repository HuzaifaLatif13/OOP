#include <iostream>
#include <string>
using namespace std;
class Month
{
private:
    string month;
    int number;

public:
    Month()
    {
        this->month = "January";
        this->number = 1;
    }
    void setMonthNumber()
    {
        if (month == "January")
        {
            number = 1;
        }
        else if (month == "February")
        {
            number = 2;
        }
        else if (month == "March")
        {
            number = 3;
        }
        else if (month == "April")
        {
            number = 4;
        }
        else if (month == "May")
        {
            number = 5;
        }
        else if (month == "June")
        {
            number = 6;
        }
        else if (month == "July")
        {
            month = 7;
        }
        else if (month == "August")
        {
            number = 8;
        }
        else if (month == "September")
        {
            number = 9;
        }
        else if (month == "October")
        {
            number = 10;
        }
        else if (month == "November")
        {
            number = 11;
        }
        else
        {
            number = 12;
        }
    }
    Month(string month)
    {
        this->month = month;
        setMonthNumber();
    }
    void setMonthName()
    {
        if (number == 1)
        {
            month == "January";
        }
        else if (number == 2)
        {
            month == "February";
        }
        else if (number == 3)
        {
            month == "March";
        }
        else if (number == 4)
        {
            month == "April";
        }
        else if (number == 5)
        {
            month == "May";
        }
        else if (number == 6)
        {
            month == "June";
        }
        else if (number == 7)
        {
            month == "July";
        }
        else if (number == 8)
        {
            month == "August";
        }
        else if (number == 9)
        {
            month == "September";
        }
        else if (number == 10)
        {
            month == "October";
        }
        else if (number == 11)
        {
            month == "November";
        }
        else
        {
            month = "December";
        }
    }
    Month(int number)
    {
        this->number = number;
        setMonthName();
    }
    void setMonth()
    {
        cout << "\nEnter name of month: ";
        cin >> month;
        while (month != "January" || month != "February" || month != "March" || month != "April" || month != "May" || month != "June" || month != "July" || month != "August" || month != "September" || month != "October" || month != "November" || month != "December")
        {
            cout << "\nInvalid month. Enter again: ";
            cin >> month;
        }
    }
    string getMonth()
    {
        return month;
    }
};