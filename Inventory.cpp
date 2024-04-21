#include <iostream>
using namespace std;
class Inventory
{
private:
    int itemNum;
    int quantity;
    double cost;
    double totalCost;

public:
    Inventory(int itemNum = 0, int quantity = 0, double cost = 0)
    {
        this->itemNum = itemNum;
        this->quantity = quantity;
        this->cost = cost;
        setTotalCost();
    }
    void setItemNumber()
    {
        cout << "\nEnter the item number of item: ";
        cin >> itemNum;
        while (itemNum < 0)
        {
            cout << "\nInvalid item number. enter again: ";
            cin >> itemNum;
        }
    }
    int getItemNum()
    {
        return itemNum;
    }
    void setQuantity()
    {
        cout << "\nEnter the number of items: ";
        cin >> quantity;
        while (quantity < 0)
        {
            cout << "\nInvalid quantity. Enter again: ";
            cin >> quantity;
        }
    }
    int getQuantity()
    {
        return quantity;
    }
    void SetCostOfitem()
    {
        cout << "\nEnter the cost for item: ";
        cin >> cost;
        while (cost < 0)
        {
            cout << "\nInvalid cost. Enter again: ";
            cin >> cost;
        }
    }
    double getCost()
    {
        return cost;
    }
    void setTotalCost()
    {
        totalCost = quantity * cost;
    }
    double getTotalCost()
    {
        return totalCost;
    }
    void display()
    {
        cout << "\n---Inventry details--->" << endl;
        cout << "\n1- Item Number: " << itemNum;
        cout << "\n2- Quantity: " << quantity;
        cout << "\n3- Cost: " << cost << " Rupees";
        cout << "\nTotal Bil: " << getTotalCost() << " Rupees";
    }
};
int main()
{
    Inventory i(1, 2, 5);
    i.display();
    i.setItemNumber();
    i.setQuantity();
    i.SetCostOfitem();
    i.setTotalCost();
    i.display();
}