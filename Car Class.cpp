#include <iostream>
#include <string>
using namespace std;
class Car
{
private:
    int yearModel;
    string make;
    int speed;

public:
    Car(int yearModel = 0, string make = "Null")
    {
        this->yearModel = yearModel;
        this->make = make;
        speed = 0;
    }
    void setCar()
    {
        cout << "\nEnter the year model for car: ";
        cin >> yearModel;
        cout << "\nEnter The Company name of the Car: ";
        cin >> make;
        cout << "\nEnter the current speed of the car: ";
        cin >> speed;
    }
    int getYearModel()
    {
        return yearModel;
    }
    string getMake()
    {
        return make;
    }
    int getSpeed()
    {
        return speed;
    }
    void display()
    {
        cout << "\nThe Year model of the car is: " << yearModel;
        cout << "\nThe Company name of the Car is: " << make;
        cout << "\nThe current speed of the car is: " << speed;
    }
    int accelerate()
    {
        speed += 5;
        return speed;
    }
    int brake()
    {
        speed -= 5;
        return speed;
    }
};
int main()
{
    Car c(2023, "Suzuki");
    c.display();
    cout << "\nAfter calling the Accelerate function we have: " << endl;
    for (int i = 0; i < 5; i++)
    {
        c.accelerate();
        cout << "\nThe current speed of the car " << i + 1 << " is: " << c.getSpeed();
    }
    cout << "\nNow calling the Brake function we have: " << endl;
    for (int i = 0; i < 5; i++)
    {
        c.brake();
        cout << "\nThe current speed of the car " << i + 1 << " is: " << c.getSpeed();
    }
}