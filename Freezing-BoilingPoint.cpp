// freezing and boiling points
#include <iostream>
using namespace std;
class freezinAndBoilingPoint
{
private:
    double freezingPointOfEthyl;
    double freezingPointOfOxygen;
    double freezingPointOfWater;
    double boilingPointOfEthyl;
    double boilingPointOfOxygen;
    double boilingPointOfWater;

public:
    freezinAndBoilingPoint(double freezingPointOfEthyl = 0, double freezingPointOfOxygen = 0, double freezingPointOfWater = 0, double boilingPointOfEthyl = 0, double boilingPointOfOxygen = 0, double boilingPointOfWater = 0)
    {
        this->freezingPointOfEthyl = freezingPointOfEthyl;
        this->freezingPointOfOxygen = freezingPointOfOxygen;
        this->freezingPointOfWater = freezingPointOfWater;
        this->boilingPointOfEthyl = boilingPointOfEthyl;
        this->boilingPointOfOxygen = boilingPointOfOxygen;
        this->boilingPointOfWater = boilingPointOfWater;
    }
    void setFreezingPointOfEthyl()
    {
        cout << "\nFreezing point of Ethyl: ";
        cin >> freezingPointOfEthyl;
        while (freezingPointOfEthyl > -173)
        {
            cout << "\nInvalid Freezing point. Enter again: ";
            cin >> freezingPointOfEthyl;
        }
    }
    double getFreezingPointOfEthyl()
    {
        return freezingPointOfEthyl;
    }
    void setBoilingPointOfEthyl()
    {
        cout << "\nboiling point of Ethyl: ";
        cin >> boilingPointOfEthyl;
        while (boilingPointOfEthyl < 172)
        {
            cout << "\nInvalid boiling point. Enter again: ";
            cin >> boilingPointOfEthyl;
        }
    }
    double getBoilingPointOfEthyl()
    {
        return boilingPointOfEthyl;
    }

    void setFreezingPointOfOxygen()
    {
        cout << "\nFreezing point of Oxygen: ";
        cin >> freezingPointOfOxygen;
        while (freezingPointOfOxygen > -362)
        {
            cout << "\nInvalid Freezing point. Enter again: ";
            cin >> freezingPointOfOxygen;
        }
    }
    double getFreezingPointOfOxygen()
    {
        return freezingPointOfOxygen;
    }
    void setBoilingPointOfOxygen()
    {
        cout << "\nboiling point of Oxygen: ";
        cin >> boilingPointOfOxygen;
        while (boilingPointOfOxygen < -306)
        {
            cout << "\nInvalid boiling point. Enter again: ";
            cin >> boilingPointOfOxygen;
        }
    }
    double getBoilingPointOfOxygen()
    {
        return boilingPointOfOxygen;
    }

    void setFreezingPointOfWater()
    {
        cout << "\nFreezing point of Water: ";
        cin >> freezingPointOfWater;
        while (freezingPointOfWater > 32)
        {
            cout << "\nInvalid Freezing point. Enter again: ";
            cin >> freezingPointOfWater;
        }
    }
    double getFreezingPointOfWater()
    {
        return freezingPointOfWater;
    }
    void setBoilingPointOfWater()
    {
        cout << "\nboiling point of Water: ";
        cin >> boilingPointOfWater;
        while (boilingPointOfWater < 212)
        {
            cout << "\nInvalid boiling point. Enter again: ";
            cin >> boilingPointOfWater;
        }
    }
    double getBoilingPointOfWater()
    {
        return boilingPointOfWater;
    }

    void display()
    {
        cout << "\nThe freezing point of Ethyl alcohal is: " << freezingPointOfEthyl;
        cout << "\nThe boiling point of Ethyl alcohal is: " << boilingPointOfEthyl;
        cout << "\nThe freezing point of Oxygen is: " << freezingPointOfOxygen;
        cout << "\nThe boiling point of Oxygen is: " << boilingPointOfOxygen;
        cout << "\nThe freezing point of Water is: " << freezingPointOfWater;
        cout << "\nThe boiling point of Water is: " << boilingPointOfWater;
    }
    bool isEthylFreezing()
    {
        if (freezingPointOfEthyl <= -173)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEthylBoiling()
    {
        if (boilingPointOfEthyl >= 172)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isOxygenFreezing()
    {
        if (freezingPointOfOxygen <= -362)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isOxygenBoiling()
    {
        if (boilingPointOfOxygen >= -306)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isWaterFreezing()
    {
        if (freezingPointOfWater <= 32)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isWaterBoiling()
    {
        if (boilingPointOfWater >= 212)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    double temp = 0;
    freezinAndBoilingPoint f(-173, -362, 32, 172, -306, 212);
    f.display();
    f.setFreezingPointOfEthyl();
    f.setFreezingPointOfOxygen();
    f.setFreezingPointOfWater();
    f.setBoilingPointOfEthyl();
    f.setBoilingPointOfOxygen();
    f.setBoilingPointOfWater();
    // f.display();
    cout << "\nEnter a temperature: ";
    cin >> temp;
    if (f.isEthylFreezing() && temp <= f.getFreezingPointOfEthyl())
    {
        cout << "\nAt temperature " << temp << " Ethyl will freez. " << endl;
    }
    if (f.isEthylBoiling() && temp >= f.getBoilingPointOfEthyl())
    {
        cout << "\nAt temperature " << temp << " Ethyl will boil. " << endl;
    }
    if (f.isOxygenFreezing() && temp <= f.getFreezingPointOfOxygen())
    {
        cout << "\nAt temperature " << temp << " Oxygen will freez. " << endl;
    }
    if (f.isOxygenBoiling() && temp >= f.getBoilingPointOfOxygen())
    {
        cout << "\nAt temperature " << temp << " Oxygen will boil. " << endl;
    }
    if (f.isWaterFreezing() && temp <= f.getFreezingPointOfWater())
    {
        cout << "\nAt temperature " << temp << " Water will freez. " << endl;
    }
    if (f.isWaterBoiling() && temp >= f.getBoilingPointOfWater())
    {
        cout << "\nAt temperature " << temp << " Water will boil. " << endl;
    }
    return 0;
}