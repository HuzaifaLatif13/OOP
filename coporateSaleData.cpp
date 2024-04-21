#include <iostream>
#include <string>
using namespace std;
class coporateSaleData
{
private:
    string divname;
    double firstQuarter;
    double secondQuarter;
    double thirdQuarter;
    double forthQuarter;
    double annualSale;
    double averageSale;

public:
    coporateSaleData(double firstQuarter, double secondQuarter, double thirdQuarter, double forthQuarter, string divname)
    {
        this->firstQuarter = firstQuarter;
        this->secondQuarter = secondQuarter;
        this->thirdQuarter = thirdQuarter;
        this->forthQuarter = forthQuarter;
        this->averageSale = 0;
        this->annualSale = 0;
        this->divname = divname;
    }
    void setQuaters()
    {
        cout << "\nEnter the sales for first quarter: " << endl;
        cin >> firstQuarter;
        while (firstQuarter < 0)
        {
            cout << "\nInvalid sales-Enter again: " << endl;
            cin >> firstQuarter;
        }
        cout << "\nEnter the sales for second quarter: " << endl;
        cin >> secondQuarter;
        while (secondQuarter < 0)
        {
            cout << "\nInvalid sales-Enter again: " << endl;
            cin >> secondQuarter;
        }
        cout << "\nEnter the sales for third quarter: " << endl;
        cin >> thirdQuarter;
        while (thirdQuarter < 0)
        {
            cout << "\nInvalid sales-Enter again: " << endl;
            cin >> thirdQuarter;
        }
        cout << "\nEnter the sales for forth quarter: " << endl;
        cin >> forthQuarter;
        while (forthQuarter < 0)
        {
            cout << "\nInvalid sales-Enter again: " << endl;
            cin >> forthQuarter;
        }
    }
    void setDivname()
    {
        cout << "\nEnter Name of the division: ";
        cin >> divname;
        while (divname != "East" && divname != "West" && divname != "South" && divname != "North")
        {
            cout << "\nInvalid division name-Enter again: ";
            cin >> divname;
        }
    }
    string getDivName()
    {
        return divname;
    }
    double getFirstQuarter()
    {
        return firstQuarter;
    }
    double getsecondQuarter()
    {
        return secondQuarter;
    }
    double getthirdQuarter()
    {
        return thirdQuarter;
    }
    double getForthQuarter()
    {
        return forthQuarter;
    }
    double calculatingAverageSale()
    {
        averageSale = (firstQuarter + secondQuarter + thirdQuarter + forthQuarter) / 4;
        return averageSale;
    }
    double calculatingAnnualSales()
    {
        annualSale = (firstQuarter + secondQuarter + thirdQuarter + forthQuarter);
        return annualSale;
    }
    void display()
    {
        cout << "\nThe name of the division is: " << divname;
        cout << "\nThe sales for first quarter is: " << firstQuarter;
        cout << "\nThe sales for second quarter is: " << secondQuarter;
        cout << "\nThe sales for third quarter is: " << thirdQuarter;
        cout << "\nThe sales for forth quarter is: " << forthQuarter;
        cout << "\nthe average sales are: " << averageSale;
        cout << "\nThe annual sales is: " << annualSale;
    }
};
int main()
{
    coporateSaleData c(123.4, 345.6, 178.9, 567.7, "East");
    c.display();
    c.setDivname();
    c.setQuaters();
    c.calculatingAverageSale();
    c.calculatingAnnualSales();
    c.display();
    return 0;
}