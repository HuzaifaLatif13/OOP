#include<iostream>
using namespace std;
class Employee
{
    private:
        int emp_no;
        char *emp_name;
        friend bool operator==(Employee& e1,Employee& e2); 
    public:
        Employee(char* name,int emp_no);
        Employee();
        void setEmpName(char* emp_name);
        void setEmpNum(int emp_no);
        char getEmpName();
        int getEmpNum();
        void displayEmp();
        Employee(const Employee& e1);
        

};
//default constructor
Employee::Employee()
{
    cout<<"\nEmployee Constructor called!";
    this->emp_name = new char[50];
    this->emp_name = "Null";
    this->emp_no = 0;

}
//parameterised constructor
Employee::Employee(char* emp_name,int emp_no)
    {
        cout<<"\nEmployee Constructor called!";
        this->emp_name = new char[50];
        this->emp_name = emp_name;
        this->emp_no = emp_no;
    }
    // set emp name
void Employee::setEmpName(char* emp_name)
  {
        this->emp_name = emp_name;
  }
    //set emp number
void Employee::setEmpNum(int emp_no)
  {
    this->emp_no = emp_no;
  }
  // get emp name
char Employee::getEmpName()
  {
    return *emp_name;
  }
  //get emp number
int Employee::getEmpNum()
  {
    return emp_no;
  }
  //display
  void Employee::displayEmp()
  {
    cout<<"\nThe name of the employee is: "<<emp_name<<"\nThe employee number is: "<<emp_no<<endl;
  }
  //copy constructor
  Employee::Employee(const Employee& e1)
  {
    this->emp_name = e1.emp_name;
    this->emp_no = e1.emp_no;
  }
  //over load == operator
  bool operator==(Employee& e1,Employee& e2)
  {
    if(e1.emp_name==e2.emp_name && e1.emp_no==e2.emp_no)
    {
        return true;
    }
    else 
    return false;

}
//second class 
class ProductionWorker:public Employee
{
    private:
        int shift;
        double hourly_pay;
        friend bool operator==(ProductionWorker& p1,ProductionWorker& p2); 
    public:
        ProductionWorker();
        ProductionWorker( char* emp_name,  int emp_no,int shift,double hourly_pay);
        void setShift(int shift);
        void setHourlyRate(double hourly_pay);
        int getShift();
        double getHourlyPay();
        void displayPro();
        ProductionWorker(const ProductionWorker& p1);
};
//default
ProductionWorker::ProductionWorker()
{
    shift = 0;
    hourly_pay = 0.0;
}
//parameterised constructor
ProductionWorker::ProductionWorker( char* emp_name,  int emp_no,int shift,double hourly_pay):Employee( emp_name ,emp_no)
{
    this->shift = shift;
    this->hourly_pay = hourly_pay;
}
//set shift
void ProductionWorker::setShift(int shift)
{
    this->shift = shift;
}
//set hourly rate
void ProductionWorker::setHourlyRate(double hourly_pay)
{
    this->hourly_pay = hourly_pay;
}
//get shift
int ProductionWorker::getShift()
{
    return shift;
}
//get hourly rate
double ProductionWorker::getHourlyPay()
{
    return hourly_pay;
}
// display
void ProductionWorker::displayPro()
{
    cout<<"\nI am a production worker!"<<endl;
    cout<<"\nThe shift is: "<<shift<<"\nThe hourly pay rate is: "<<hourly_pay<<endl;
}
//copy constructor
ProductionWorker::ProductionWorker(const ProductionWorker& p1)
{
    this->shift = p1.shift;
    this->hourly_pay = p1.hourly_pay;
}
//overloading == operator
bool operator==(ProductionWorker& p1,ProductionWorker& p2)
  {
    if(p1.shift==p2.shift && p1.hourly_pay==p2.hourly_pay)
    {
        return true;
    }
    else 
    return false;
}
//third class
class TeamLeader:public ProductionWorker
{
    private:
        double bonus;
        int total_hours;
        int attended_hours;
    public:
        TeamLeader(char* emp_name,  int emp_no,int shift,double hourly_pay,double bonus,int total_hours,int attended_hours);
};
TeamLeader::TeamLeader(char* emp_name,  int emp_no,int shift,double hourly_pay,double bonus,int total_hours,int attended_hours) :ProductionWorker(shift,hourly_pay,emp_name,emp_no)
{
    this->bonus = bonus;
    this->total_hours = total_hours;
    this->attended_hours = attended_hours;
}
int main()
{
    Employee e("Ahmad",1);
    e.displayEmp();
    Employee *e1;
    e1 = new Employee;
    int eno;
    char name[50];
    cout<<"\nEnter name of Employee: "<<endl;
    cin>>name;
    cout<<"Enter number of Employee: "<<endl;
    cin>>eno;
    e1->setEmpName(name);
    e1->setEmpNum(eno);
    e1->displayEmp();
    e.getEmpName() == e1->getEmpName();
    ProductionWorker p("Ahmad",1,2,1500.50);
    p.displayPro();
    ProductionWorker *p1;
    p1 = new ProductionWorker;
    int Shift;
    cout << "Enter 1 for day shift\nEnter 2 for night shift : \n";
    cin >> Shift;
    if (Shift != 1 && Shift != 2)
    {
        cout << "InCorrect Shift Number\n";
        for (int i = 0; Shift != 1 && Shift != 2; i++)
        {
            cout << "Enter correct Number of shift: \n";
            cin >> Shift;
        }
    }
    int pay;
    cout<<"\nEnter hourly pay rate: ";
    cin>>pay;
    p1->setShift(Shift);
    p1->setHourlyRate(pay);
    p1->displayPro();
    system("Pause");
    return 0;
}
