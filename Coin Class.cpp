#include <iostream>
using namespace std;
class Coin
{
private:
    string sideUp;

public:
    Coin(string sideUp = "")
    {
        this->sideUp = sideUp;
    }
    void setToss(string str)
    {
        if (str == "HeadUp" || str == "headUp")
        {
            sideUp = "HeadUp";
        }
        else if (str == "TailUp" || str == "TailUp")
        {
            sideUp = "TailUp";
        }
    }
    string getToss()
    {
        return sideUp;
    }
    void display()
    {
        cout << "\nThe Initially side of the coin is: " << sideUp;
    }
};
int main()
{
    string str1 = "HeadUp";
    int headCount = 0;
    string str2 = "tailUp";
    int tailCount = 0;
    int num;
    Coin c("HeadUp");
    c.display();
    Coin *c1;
    cout << "\nHow many time do you want to Toss the coin: ";
    cin >> num;
    while (num < 0)
    {
        cout << "\nInvalid. Enter again: ";
        cin >> num;
    }
    c1 = new Coin[num];
    for (int i = 0; i < num; i++)
    {
        string toss;
        cout << "\nEnter the result of your toss: ";
        cin >> toss;
        c1[i].setToss(toss);
        c1[i].display();
        if (toss == str1)
        {
            headCount++;
        }
        else if (toss == str2)
        {
            tailCount++;
        }
        else
        {
            cout << "\nInvalid result.";
        }
    }
    cout << "\nHead appear " << headCount << " times.";
    cout << "\nTail appear " << tailCount << " times.";
    return 0;
}