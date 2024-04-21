#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class SalesItem
{
private:
    int ID;
    char name[30];
    int price;
    int quantity;

public:
    SalesItem(int ID = 0, const char *name = "", int price = 0, int quantity = 0)
    {
        this->ID = ID;
        strcpy(this->name, name);
        this->price = price;
        this->quantity = quantity;
    }
    void setSaleItem()
    {
        cout << "\nEnter the ID number of Item: ";
        cin >> ID;
        while (ID <= 0)
        {
            cout << "\nInvalid ID. Enter again: ";
            cin >> ID;
        }
        fflush(stdin);
        cout << "\nEnter the name of Item: ";
        cin.getline(name, sizeof(name));
        cout << "\nEnter the price of Item: ";
        cin >> price;
        while (price < 0)
        {
            cout << "\nInvalid price. Enter again: ";
            cin >> price;
        }
        cout << "\nEnter the quanty of Item: ";
        cin >> quantity;
        while (quantity < 0)
        {
            cout << "\nInvalid quantity. Enter again: ";
            cin >> quantity;
        }
    }
    int getId()
    {
        return ID;
    }
    char getname()
    {
        return *name;
    }
    int getPrice()
    {
        return price;
    }
    int getQuantity()
    {
        return quantity;
    }
    bool incrementQuantity(int quant)
    {
        if (quant <= 0)
        {
            return false;
        }
        else
        {
            quantity += quant;
            return true;
        }
    }
    bool decrementQuantity(int quant)
    {
        if (quant <= 0 || quant > quantity)
        {
            return false;
        }
        else
        {
            quantity -= quant;
            return true;
        }
    }
    void display()
    {
        cout << "\nItem Details: " << endl;
        cout << "\nName: ";
        for (int i = 0; name[i] != '\0'; i++)
        {
            cout << name[i];
        }
        cout << "\nThe Id: " << ID << "\nThe price: " << price << "\nThe quantity: " << quantity << endl;
    }
};
int main()
{
    SalesItem s(1, "Feast", 150, 3);
    s.display();
    s.setSaleItem();
    s.display();
    cout << "\nAfter incrementing,The quantity is: " << s.incrementQuantity(6);
    s.display();
    cout << "\nAfter decrementing,The quantity is: " << s.decrementQuantity(6);
    s.display();
}