#include <iostream>
#include <string>
using namespace std;
class student
{
private:
    string name, grade;
    int idnum, *testScore, num;
    float average;
    int total;

public:
    student(string name = "null", string grade = "null", int idnum = 0, int num = 0, int *testScore = NULL, int total = 0)
    {
        this->name = name;
        this->grade = grade;
        this->idnum = idnum;
        for (int i = 0; i < 5; i++)
        {
            this->testScore = testScore;
        }
        this->average = 0.0;
        this->num = num;
        this->total = total;
    }
    void setStudentName()
    {
        cout << "\nEnter name of the student: ";
        cin >> name;
    }
    void setStudentID()
    {
        cout << "\nEnter id number of the student: ";
        cin >> idnum;
    }
    void setStudentmarks()
    {

        cout << "\nEnter the number of tests: ";
        cin >> num;
        while (num < 0)
        {
            cout << "\nInvalid numbers.Enter number once again: ";
            cin >> num;
        }
        cout << "\nEnter The total marks: ";
        cin >> total;
        while (total < 0)
        {
            cout << "\nInvalid total marks.Enter again: ";
            cin >> total;
        }
        testScore = new int[num];
        for (int i = 0; i < num; i++)
        {
            cout << "\nEnter the scores of test " << i + 1 << ": ";
            cin >> testScore[i];
            while (testScore[i] < 0 || testScore[i] > total)
            {
                cout << "\nInvalid test score.Enter again: ";
                cin >> testScore[i];
            }
        }
    }

    string getName()
    {
        return name;
    }
    int getIdNum()
    {
        return idnum;
    }
    int *getScore()
    {
        return testScore;
    }
    void display()
    {
        cout << "\n<---Result Card--->" << endl;
        cout << "\nName: " << name;
        cout << "\nId: " << idnum;
        cout << "\nThe marks of the student in different tests are: " << endl;
        for (int i = 0; i < num; i++)
        {
            cout << "TestMarks " << i + 1 << "=  " << testScore[i] << endl;
        }
        calculateAverage();
        cout << "Average: " << average;
        FindGrades();
        cout << endl;
    }
    float calculateAverage()
    {
        float sum = 0.0;
        for (int i = 0; i < num; i++)
        {
            sum += testScore[i];
        }
        average = sum / num;
        return average;
    }
    int getNum()
    {
        return num;
    }
    void FindGrades()
    {
        float sum = 0.0;
        for (int i = 0; i < num; i++)
        {
            sum += testScore[i];
        }
        int x = num * total;

        int score = (sum / x) * 100;

        if (score >= 90)
        {
            cout << "\nCongratulations!! Your Grade is A." << endl;
        }
        else if (score < 90 && score >= 81)
        {
            cout << "\nCongratulations!! Your Grade is B." << endl;
        }
        else if (score < 80 && score >= 71)
        {
            cout << "\nYour Grade is C." << endl;
        }
        else if (score < 70 && score >= 61)
        {
            cout << "\nYour Grade is D." << endl;
        }
        else if (score < 60)
        {
            cout << "\nOoops!!!You got fail.";
        }
    }
};

void searchId(student *s, int id, int numOfStudent)
{
    int idFlag = 0;
    for (int i = 0; i < numOfStudent; i++)
    {
        if (s[i].getIdNum() == id)
        {
            s[i].display();
            idFlag = 1;
        }
    }
    if (idFlag == 0)
    {
        cout << "\nID not exist." << endl;
    }
}
int main()
{
    int numOfStudents = 0, tScore[5] = {40, 40, 40, 40, 40};
    student s("Husna", "A", 1, 5, tScore, 50);
    s.display();
    student *s1;
    cout << "\nEnter the number of student to store data: ";
    cin >> numOfStudents;
    while (numOfStudents < 0)
    {
        cout << "\nInvalid number.Enter again: ";
        cin >> numOfStudents;
    }
    s1 = new student[numOfStudents];
    for (int i = 0; i < numOfStudents; i++)
    {
        s1[i].setStudentName();
        s1[i].setStudentID();
        s1[i].setStudentmarks();
    }
    for (int i = 0; i < numOfStudents; i++)
    {
        s1[i].display();
    }
    int id = 0;
    cout << "\nEnter Id to searchout.";
    cin >> id;
    searchId(s1, id, numOfStudents);
}