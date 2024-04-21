#include <iostream>
#include <string>
#include <time.h>
using namespace std;
class coin
{
private:
    string sideUp;

public:
    coin(string sideUp = "")
    {
        this->sideUp = sideUp;
    }
    void display()
    {
        cout << "\nInitially, The side of the coin is: " << sideUp;
    }
    void setToss(string toss)
    {
        if (toss == "HeadUp" || toss == "headUp" || toss == "headup" || toss == "Headup")
        {
            sideUp = toss;
        }
        else if (toss == "TailUp" || toss == "tailUp" || toss == "tailup" || toss == "Tailup")
        {
            sideUp = toss;
        }
    }
    string getToss()
    {
        return sideUp;
    }
};
int main()
{
string str1 = "HeadUp";
string str2 = "headUp";
string str3 = "headup";
string str4 = "Headup";
int hcount = 0;
string str5 = "TailUp";
string str6 = "tailUp";
string str7 = "tailup";
string str8 = "Tailup";
int tcount = 0;
coin c("Tailup");
c.display();
coin *c1;
int num;
cout << "\nHow many times do you want to toss the coin: ";
cin >> num;
while (num < 0)
{
    cout << "\nInvalid number. Enter again: ";
    cin >> num;
}
c1 = new coin[num];
for (int i = 0; i < num; i++)
{
    string toss;
    cout << "\nEnter the result of your toss: ";
    cin >> toss;
    c1[i].setToss(toss);
    if (str1 == c1[i].getToss() || str2 == c1[i].getToss() || str3 == c1[i].getToss() || str4 == c1[i].getToss())
    {
        hcount++;
    }
    else if (str5 == c1[i].getToss() || str6 == c1[i].getToss() || str7 == c1[i].getToss() || str8 == c1[i].getToss())
    {
        tcount++;
    }
    else
    {
        cout << "\nInvalid result.";
    }
}
cout << "\nHead appears " << hcount << " times.";
cout << "\nTail appears " << tcount << " times.";
    int goal = 0;
    int tosscount = 0;
    coin q("HeadUp");
    coin d("HeadUp");
    coin n("HeadUp");
    while (goal < 1.0)
    {
        string tossResult = (rand() % 2 == 0) ? "HeadUp" : "TailUp";
        q.setToss(tossResult);
        d.setToss(tossResult);
        n.setToss(tossResult);
        if (q.getToss() == "HeadUp")
        {
            goal += 0.25;
        }
        else
        {
            goal += 0;
        }
        if (d.getToss() == "HeadUp")
        {
            goal += 0.1;
        }
        else
        {
            goal += 0;
        }
        if (n.getToss() == "HeadUp")
        {
            goal += 0.05;
        }
        else
        {
            goal += 0;
        }
        tosscount++;
    }
    if (goal == 1.0)
    {
        cout << "\nCongratulations!!You win the game.";
        cout << "\nBut you try for " << tosscount << " times.";
    }

    return 0;
}