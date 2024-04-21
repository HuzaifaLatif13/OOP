#include <iostream>
#include <cstring>
using namespace std;
class Student
{
private:
    int ID;
    char name[30];
    char deptName[30];

public:
    Student(int ID = 0, char *name = "", char *deptName = "")
    {
        this->ID = ID;
        strcpy(this->name, name);

        strcpy(this->deptName, deptName);
    }
    void setStudent()
    {
        cout << "\nEnter Id: ";
        cin >> ID;
        while (ID < 0)
        {
            cout << "\nInvalid Id.Enter again: ";
            cin >> ID;
        }
        cout << "\nEnter name: ";
        cin.ignore();
        cin.getline(name, sizeof(name));
        cout << "\nEnter department: ";
        cin.getline(deptName, sizeof(deptName));
    }
    int getID()
    {
        return ID;
    }
    char getName(int ind)
    {
        return name[ind];
    }
    char getDeptName(int ind)
    {
        return deptName[ind];
    }
    void display()
    {
        cout << "\n--->Student Detail--->" << endl;
        cout << "\nID: " << getID();
        cout << "\nName: ";
        for (int i = 0; i < name[i] != '\0'; i++)
        {
            cout << getName(i);
        }
        cout << "\nDepartment: ";
        for (int i = 0; deptName[i] != '\0'; i++)
        {
            cout << getDeptName(i);
        }
    }
};
int main()
{
    int size;
    Student s(1, "abcd", "pucit");
    s.display();
    s.setStudent();
    s.display();
    cout << "\nEnter the size of Student structure: ";
    cin >> size;

    while (size < 0)
    {
        cout << "\nValid size. Enter again: ";
        cin >> size;
    }
    cout << size;
    Student *s1;
    s1 = new Student[size];
    cout << "*";
    for (int i = 0; i < size; i++)
    {
        s1[i].setStudent();
    }
    for (int i = 0; i < size; i++)
    {
        s1[i].display();
    }
    return 0;
}