
#include <iostream>
using namespace std;
class corporateSales
{
private:
    int arr[4];
    static int totalsale;

public:
    corporateSales()
    {
        for (int i = 0; i < 4; i++)
        {
            this->arr[i] = 0;
        }
        this->totalsale = 0;
    }
    corporateSales(int *arr1)
    {
        for (int i = 0; i < 4; i++)
        {
            this->arr[i] = arr1[i];
        }
        this->totalsale = 0;
    }
    void calCulateTotalCost()
    {
        this->totalsale = 0;
        for (int i = 0; i < 4; i++)
        {
            totalsale += arr[i];
        }
        cout << "\nAnd the sales for the entire year is: " << totalsale;
    }

    void setSaleOfEachQuarter(int saleOfQ1, int saleOfQ2, int saleOfQ3, int saleOfQ4)
    {
        this->arr[0] = saleOfQ1;
        this->arr[1] = saleOfQ2;
        this->arr[2] = saleOfQ3;
        this->arr[3] = saleOfQ4;
    }
    void display()
    {
        cout << "\n--->Divisions data--->" << endl;
        cout << "\nThe sales of each 4 quarters of each division is: "
             << " ";
        for (int i = 0; i < 4; i++)
        {
            cout << arr[i] << " ";
        }
        calCulateTotalCost();
    }
};
int corporateSales::totalsale = 0;
int main()
{
    int arr[4];
    int saleOfQ1 = 0;
    int saleOfQ2 = 0;
    int saleOfQ3 = 0;
    int saleOfQ4 = 0;
    int size;
    cout << "\nEnter the Sales for each quarter: " << endl;
    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }
    corporateSales c(arr);
    c.display();
    corporateSales *c1;
    cout << "\nEnter the number of divisions: ";
    cin >> size;
    while (size < 0)
    {
        cout << "\nInvalid number of divisions. Enter again: ";
        cin >> size;
    }
    c1 = new corporateSales[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Division " << i + 1 << " :" << endl;
        cout << "\nEnter the sales for fisrt quarter: ";
        cin >> saleOfQ1;
        while (saleOfQ1 < 0)
        {
            cout << "\nInvalid sales: Enter again: ";
            cin >> saleOfQ1;
        }
        cout << "\nEnter the sales for second quarter: ";
        cin >> saleOfQ2;
        while (saleOfQ2 < 0)
        {
            cout << "\nInvalid sales: Enter again: ";
            cin >> saleOfQ2;
        }
        cout << "\nEnter the sales for third quarter: ";
        cin >> saleOfQ3;
        while (saleOfQ3 < 0)
        {
            cout << "\nInvalid sales: Enter again: ";
            cin >> saleOfQ3;
        }
        cout << "\nEnter the sales for forth quarter: ";
        cin >> saleOfQ4;
        while (saleOfQ4 < 0)
        {
            cout << "\nInvalid sales: Enter again: ";
            cin >> saleOfQ4;
        }
        c1[i].setSaleOfEachQuarter(saleOfQ1, saleOfQ2, saleOfQ3, saleOfQ4);
        c1[i].display();
    }
    return 0;
}