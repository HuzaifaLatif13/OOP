#include <iostream>
#include <math.h>
using namespace std;
class mortGage
{
private:
    double amountOfLoan;
    double interestRate;
    int numOfYears;

public:
    mortGage(double amountOfLoan = 0, double interestRate = 0, int numOfYears = 0)
    {
        this->amountOfLoan = amountOfLoan;
        this->interestRate = interestRate;
        this->numOfYears = numOfYears;
    }
    void setAmountOfLoan()
    {
        cout << "\nEnter The Doller amount of loan: ";
        cin >> amountOfLoan;
        while (amountOfLoan < 0)
        {
            cout << "\nInvalid Amount. Enter again: ";
            cin >> amountOfLoan;
        }
    }
    double getAmountOfLoan()
    {
        return amountOfLoan;
    }
    void setInterestRate()
    {
        cout << "\nEnter Interest rate: ";
        cin >> interestRate;
        while (interestRate < 0)
        {
            cout << "\nInvalid interest rate. Enter again: ";
            cin >> interestRate;
        }
    }
    double getInterestRate()
    {
        return interestRate;
    }
    void setNumOfYears()
    {
        cout << "\nEnter the number of years: ";
        cin >> numOfYears;
        while (numOfYears < 0)
        {
            cout << "\nInvalid number of years. Enter again: ";
            cin >> numOfYears;
        }
    }
    int getNumOfYears()
    {
        return numOfYears;
    }
    double calculatingmonthlypayment()
    {
        double term = 0, monthlypayment = 0;
        term = pow((1 + (interestRate / 12)), 12 * numOfYears);
        monthlypayment = (amountOfLoan * (interestRate / 12) * term) / (term - 1);
        return monthlypayment;
    }
    void display()
    {
        cout << "\nThe amount of loan is dollers is: " << amountOfLoan << "&";
        cout << "\nThe interest rate on loan is: " << interestRate << "&";
        cout << "\nThe number of years to pay the loan is: " << numOfYears;
        cout << "\nThe monthly payment that will be pay to the bank will be: " << calculatingmonthlypayment();
        cout << "\nThe amount that has been paid to the bank in a complete year is: " << 12 * calculatingmonthlypayment();
        cout << "\nAnd the amont that has been paid till the yeas entered by the user are: " << numOfYears * calculatingmonthlypayment();
    }
};
int main()
{
    mortGage m(1200, 100, 1);
    m.display();
    m.setAmountOfLoan();
    m.setInterestRate();
    m.setNumOfYears();
    m.display();
}