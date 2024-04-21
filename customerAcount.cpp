#include <iostream>
#include <string>
using namespace std;
class customerAcount
{
private:
    string name, address, city, state, zip, telephone, dateOfLastPayment;
    double acountBalance;

public:
    customerAcount(string name = "Null", string address = "Null", string city = "Null", string state = "Null", string zip = "Null", string telephone = "Null", string dateOfLastPayment = "Null", double acountBalance = 0.0)
    {
        this->name = name;
        this->address = address;
        this->city = city;
        this->state = state;
        this->zip = zip;
        this->telephone = telephone;
        this->dateOfLastPayment = dateOfLastPayment;
        this->acountBalance = acountBalance;
    }
    void setcustomername()
    {
        cout << "\nEnter name of customer: ";
        cin >> name;
    }
    void setcustomeraddress()
    {
        cout << "\nEnter address of customer: ";
        cin >> address;
    }
    void setcustomerCity()
    {
        cout << "\nEnter city name: ";
        cin >> city;
    }
    void setcustomerState()
    {
        cout << "\nEnter state: ";
        cin >> state;
    }
    void setcustomerZip()
    {
        cout << "\nEnter zipcode of customer: ";
        cin >> zip;
    }
    void setcustomerTelephone()
    {
        cout << "\nEnter telephone: ";
        cin >> telephone;
    }
    void setcustomerDateOfLastPay()
    {
        cout << "\nEnter lastDate of payment: ";
        cin >> dateOfLastPayment;
    }
    void setcustomerAccountBalance()
    {
        cout << "\nEnter acount balance: ";
        cin >> acountBalance;
        while (acountBalance < 0)
        {
            cout << "\ninvalid account balance-Enter again: ";
            cin >> acountBalance;
        }
    }
    double getBalance()
    {
        return acountBalance;
    }
    string getName()
    {
        return name;
    }
    string getAddress()
    {
        return address;
    }
    string getCity()
    {
        return city;
    }
    string getZip()
    {
        return zip;
    }
    string getstate()
    {
        return state;
    }
    string getTelephone()
    {
        return telephone;
    }
    string getdateOfLastPayment()
    {
        return dateOfLastPayment;
    }
    void display()
    {
        cout << "\nThe name of customer is: " << name;
        cout << "\nthe address of customer is: " << address;
        cout << "\nThe name of city is: " << city;
        cout << "\nthe state of customer is: " << state;
        cout << "\nthe zip code of customer is: " << zip;
        cout << "\nThe telephone number of customer is: " << telephone;
        cout << "\nThe date of last payment is: " << dateOfLastPayment;
        cout << "\nthe account balance is: " << acountBalance << endl;
    }
};
void searchAccount(customerAcount *c, string name, int size)
{
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if (c[i].getName() == name)
        {
            c[i].display();
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "\nUser data not found." << endl;
    }
}
int main()
{
    string name;
    customerAcount c("Husna", "Muraliwala", "Gujranwala", "Pakistan", "112244", "03230744553", "25july2023", 75000);
    c.display();
    customerAcount *c1;
    int size;
    cout << "\nHow many person do you want to add: ";
    cin >> size;
    while (size < 0)
    {
        cout << "\nInvalid size.Enter again: ";
        cin >> size;
    }
    c1 = new customerAcount[size];
    for (int j = 0; j < size; j++)
    {
        cout << "\nPerson " << j + 1 << " data" << endl;
        int ch, nflag = 0, aflag = 0, cflag = 0, sflag = 0, Tflag = 0, zflag = 0, dflag = 0, Accflag = 0;
        cout << "\nWe have \n1- Name\n2- Address\n3- City\n4- State\n5- Zipcode\n6- Telephone number\n7- DateOflastPayment\n8- accountBalance" << endl;
        while (nflag != 1 || aflag != 1 || cflag != 1 || sflag != 1 || Tflag != 1 || zflag != 1 || dflag != 1 || Accflag != 1)
        {
            cout << "\nEnter your choice??";
            cin >> ch;
            while (ch < 1 && ch > 8)
            {
                cout << "\nInvalid choice-Enter again: ";
                cin >> ch;
            }
            switch (ch)
            {
            case 1:
                c1[j].setcustomername();
                nflag = 1;
                break;
            case 2:
                c1[j].setcustomeraddress();
                aflag = 1;
                break;
            case 3:
                c1[j].setcustomerCity();
                cflag = 1;
                break;
            case 4:
                c1[j].setcustomerState();
                sflag = 1;
                break;
            case 5:
                c1[j].setcustomerZip();
                zflag = 1;
                break;
            case 6:
                c1[j].setcustomerTelephone();
                Tflag = 1;
                break;
            case 7:
                c1[j].setcustomerDateOfLastPay();
                dflag = 1;
                break;
            case 8:
                c1[j].setcustomerAccountBalance();
                Accflag = 1;
                break;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << "\nPerson " << i + 1 << " data" << endl;
        c1[i].display();
    }
    cout << "\nEnter name to be searched out in the array of structures: ";
    cin >> name;
    searchAccount(c1, name, size);

    return 0;
}