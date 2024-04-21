#include <iostream>
#include <cstring>
#include <string>
#define size 40
using namespace std;
class Student
{
private:
    int rollno;
    string name;
    int *obtainedMarks;
    int totalMarks;
    int numOfQuiz;
    static int numOfStudent;

public:
    Student(int rollno = 0, string name = "NULL", int numOfQuiz = 0, int totalMarks = 10)
    {
        this->rollno = rollno;
        this->name = name;
        this->numOfQuiz = numOfQuiz;
        this->obtainedMarks = new int[numOfQuiz];
        for (int i = 0; i < numOfQuiz; i++)
        {
            this->obtainedMarks[i] = 0;
        }
        this->totalMarks = totalMarks;
        numOfStudent++;
    }
    ~Student()
    {
        delete[] obtainedMarks;
        numOfStudent--;
    }
    void setStudent()
    {
        cout << "\nEnter Name: ";
        cin >> name;
        cout << "\nEnter Rollno: ";
        cin >> rollno;
        while (rollno < 0)
        {
            cout << "\nInvalid roll number. Enter again: ";
            cin >> rollno;
        }
        cout << "\nEnter the number of quizes: ";
        cin >> numOfQuiz;
        while (numOfQuiz < 0)
        {
            cout << "\nInvalid quiz. Enter again: ";
            cin >> numOfQuiz;
        }
        cout << "\nEnter Total marks of Each quiz: ";
        cin >> totalMarks;
        while (totalMarks < 0 || totalMarks > 100)
        {
            cout << "\nInvalid total marks. Enter again: ";
            cin >> totalMarks;
        }
        delete[] obtainedMarks;
        this->obtainedMarks = new int[numOfQuiz];
        inPutMarks();
    }
    void inPutMarks()
    {

        cout << "\nEnter marks in different subjects: ";
        for (int i = 0; i < numOfQuiz; i++)
        {
            cin >> obtainedMarks[i];
            while (obtainedMarks[i] < 0 || obtainedMarks[i] > totalMarks)
            {
                cout << "\nInvalid obtained marks. Enter again: ";
                cin >> obtainedMarks[i];
            }
        }
    }
    int getNumOfStudent()
    {
        return numOfStudent;
    }
    void display()
    {
        float avg = 0.0;
        int t = 0;
        cout << "--->Student Record--->" << endl;
        cout << "\nName: " << name;
        cout << "\nRollNo: " << rollno;
        cout << "\nNum Of Quizez: " << numOfQuiz;
        cout << "\nTotal Marks: " << totalMarks;
        cout << "\nMarks Obtained in Each Quiz: " << endl;
        for (int i = 0; i < numOfQuiz; i++)
        {
            cout << "Quiz: " << i + 1 << "= ";
            cout << obtainedMarks[i] << endl;
            t += obtainedMarks[i];
        }
        avg = t / numOfQuiz;
        cout << "\nThe average marks is: " << avg;
        cout << "\nTotal Number Of Students: " << numOfStudent;
    }
    Student(const Student &s)
    {
        this->rollno = s.rollno;
        this->name = s.name;
        this->numOfQuiz = s.numOfQuiz;
        this->obtainedMarks = new int[numOfQuiz];
        for (int i = 0; i < numOfQuiz; i++)
        {
            this->obtainedMarks[i] = s.obtainedMarks[i];
        }
        this->totalMarks = s.totalMarks;
        numOfStudent++;
    }
};
int Student::numOfStudent = 0;
void printStudent(Student s)
{
    s.display();
}
int main()
{
    int nSizee = 0;
    cout << "\nEnter Total number of students: ";
    cin >> nSizee;
    while (nSizee < 0)
    {
        cout << "\nInvalid num of students. Enter again: ";
        cin >> nSizee;
    }
    Student s1[nSizee];

    for (int i = 0; i < nSizee; i++)
    {
        s1[i].setStudent();
        s1[i].display();
    }
    cout << "\nThe total number of students are: " << s1[0].getNumOfStudent(); // Access the first object for the total count
    cout << "\nCopy constructor." << endl;
    Student s2 = s1[0];
    printStudent(s2);

    return 0;
}