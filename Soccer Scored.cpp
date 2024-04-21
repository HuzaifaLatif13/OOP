#include <iostream>
#include <string>
using namespace std;
class soccerScored
{
private:
    string name;
    int playerNum;
    int scors;

public:
    soccerScored(string name = "Null", int playerNum = 0, int scors = 0)
    {
        this->name = name;
        this->playerNum = playerNum;
        this->scors = scors;
    }
    void setData()
    {
        cout << "\nenter the name of the player: ";
        cin >> name;
        cout << "\nEnter player number: ";
        cin >> playerNum;
        cout << "\nEnter points of player: ";
        cin >> scors;
    }
    string getname()
    {
        return name;
    }
    int getplayerNum()
    {
        return playerNum;
    }
    int getScor()
    {
        return scors;
    }
    void display()
    {
        cout << "\nThe name of the player is: " << name;
        cout << "\nThe palyer number is: " << playerNum;
        cout << "\nThe Scors of the paly is: " << scors;
    }
};
int main()
{
    int totalPoint = 0;
    int max = 0;
    int min = 0;
    int ind, ind1;
    soccerScored s("Husna", 1, 0);
    s.display();
    soccerScored *s1;
    s1 = new soccerScored[3];
    for (int i = 0; i < 3; i++)
    {
        s1[i].setData();
        totalPoint += s1[i].getScor();
    }

    cout << "\nThe total points for team is: " << totalPoint;
    max = s1[0].getScor();
    min = s1[0].getScor();
    for (int i = 0; i < 3; i++)
    {
        if (s1[i].getScor() > max)
        {
            max = s1[i].getScor();
            ind = i;
        }
    }
    cout << "\nThe maximum score is: ";
    s1[ind].display();
    for (int i = 0; i < 3; i++)
    {
        if (s1[i].getScor() < min)
        {
            min = s1[i].getScor();
            ind1 = i;
        }
    }
    cout << "\nThe minimum score is: ";
    s1[ind1].display();
}