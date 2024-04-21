#include <iostream>
#include <string>
using namespace std;
class dayOfYear
{
private:
    int day;
    string month;

public:
    dayOfYear(int day = 0)
    {
        this->day = day;
        setMonth();
    }
    void display()
    {
        cout << "\nThe day " << day << " would be " << month << " - " << day;
    }
    void setDay()
    {
        cout << "\nEnter Day of year: ";
        cin >> day;
        while (day < 1 || day > 365)
        {
            cout << "\nInvalid day. Enter again(1-365): ";
            cin >> day;
        }
    }
    void setMonth()
    {
        if (day >= 1 && day <= 31)
        {
            month = "January";
        }
        else if (day >= 32 && day <= 59)
        {
            month = "February";
        }
        else if (day >= 60 && day <= 90)
        {
            month = "March";
        }
        else if (day >= 91 && day <= 120)
        {
            month = "April";
        }
        else if (day >= 121 && day <= 151)
        {
            month = "May";
        }
        else if (day >= 152 && day <= 181)
        {
            month = "June";
        }
        else if (day >= 182 && day <= 212)
        {
            month = "July";
        }
        else if (day >= 213 && day <= 243)
        {
            month = "August";
        }
        else if (day >= 244 && day <= 273)
        {
            month = "September";
        }
        else if (day >= 274 && day <= 304)
        {
            month = "October";
        }
        else if (day >= 305 && day <= 334)
        {
            month = "November";
        }
        else if (day >= 335 || day <= 365)
        {
            month = "December";
        }
    }
    int getDay()
    {
        return day;
    }
};
int main()
{
    dayOfYear d(365);
    d.display();
    d.setDay();
    d.setMonth();
    d.display();
}