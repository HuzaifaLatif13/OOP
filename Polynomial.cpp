#include <iostream>
using namespace std;
class Polinomial
{
private:
    int *coef;
    int degree;
    friend Polinomial operator+(Polinomial &p1, Polinomial &p2);
    friend void operator+=(Polinomial &p1, Polinomial &p2);
    friend bool operator>(Polinomial &p1, Polinomial &p2);
    friend bool operator==(Polinomial &p1, Polinomial &p2);
    friend Polinomial operator-(Polinomial &p1, Polinomial &p2);

public:
    Polinomial(int degree)
    {
        coef = new int[degree + 1];
        for (int i = 0; i <= degree; i++)
        {
            coef[i] = 0;
        }
        this->degree = degree;
    }
    void setPolinomial(int coficients, int index)
    {
        coef[index] = coficients;
    }

    void search(int index)
    {
        cout << "\nThe Coefficinet at X^" << index << " is: " << coef[index];
    }

    ~Polinomial()
    {
        delete[] coef;
    }

    void setter(int coeficient, int index)
    {
        coef[index] = coeficient;
    }
    void display()
    {
        cout << "The polinomial is : ";
        for (int i = degree; i >= 0; i--)
        {
            if (i != 0)
            {
                cout << coef[i] << "x^" << i << " + ";
            }
            else if (i == 0)
            {
                cout << coef[i] << "x^" << i;
            }
        }
        cout << endl;
    }
};
Polinomial operator+(Polinomial &p1, Polinomial &p2)
{
    // small and large size polinomail
    int s_deg = 0, l_deg = 0;
    if (p1.degree > p2.degree)
    {
        s_deg = p2.degree;
        l_deg = p1.degree;
    }
    else if (p2.degree > p1.degree)
    {
        s_deg = p1.degree;
        l_deg = p2.degree;
    }
    else if (p1.degree == p2.degree)
    {
        s_deg = p1.degree;
        l_deg = p1.degree;
    }
    Polinomial temp(l_deg);
    // additions w r t small degree

    for (int i = 0; i <= s_deg; i++)
    {
        temp.coef[i] = p1.coef[i] + p2.coef[i];
    }

    // if polinomail is of equal size then

    for (int i = s_deg + 1; i <= l_deg; i++)
    {
        if (l_deg == p1.degree)
        {
            temp.coef[i] = p1.coef[i];
        }
        else if (l_deg == p2.degree)
        {
            temp.coef[i] = p2.coef[i];
        }
    }
    return temp;
}

void operator+=(Polinomial &p1, Polinomial &p2)
{
    // small and large size polinomail
    int s_deg = 0, l_deg = 0;
    if (p1.degree > p2.degree)
    {
        s_deg = p2.degree;
        l_deg = p1.degree;
    }
    else if (p2.degree > p1.degree)
    {
        s_deg = p1.degree;
        l_deg = p2.degree;
    }
    else if (p1.degree == p2.degree)
    {
        s_deg = p1.degree;
        l_deg = p1.degree;
    }
    Polinomial temp(l_deg);
    // additions w r t small degree

    for (int i = 0; i <= s_deg; i++)
    {
        temp.coef[i] = p1.coef[i] + p2.coef[i];
    }

    // if polinomail is of equal size then

    for (int i = s_deg + 1; i <= l_deg; i++)
    {
        if (l_deg == p1.degree)
        {
            temp.coef[i] = p1.coef[i];
        }
        else if (l_deg == p2.degree)
        {
            temp.coef[i] = p2.coef[i];
        }
    }
    delete[] p1.coef;

    p1.coef = new int[l_deg];
    p1.degree = l_deg;
    for (int i = 0; i <= l_deg; i++)
    {
        p1.coef[i] = temp.coef[i];
    }
}

bool operator>(Polinomial &p1, Polinomial &p2)
{
    if (p1.degree > p2.degree)
    {
        return true;
    }
    else if (p2.degree > p1.degree)
    {
        return false;
    }
    else if (p1.degree == p2.degree)
    {
        if (p1.coef[p1.degree] > p2.coef[p2.degree])
        {
            return true;
        }
        else if (p1.coef[p1.degree] < p2.coef[p2.degree])
        {
            return false;
        }
        else
            return true;
    }
}
bool operator==(Polinomial &p1, Polinomial &p2)
{
    if (p1.degree != p2.degree)
    {
        return false;
    }
    else
    {
        int flag = 1;
        for (int i = 0; i <= p1.degree; i++)
        {
            if (p1.coef[i] != p2.coef[i])
                flag = 0;
        }
        if (flag == 0)
            return false;
        else
            return true;
    }
}

Polinomial operator-(Polinomial &p1, Polinomial &p2)
{
    int s_deg = 0, l_deg = 0;
    if (p1.degree > p2.degree)
    {
        s_deg = p2.degree;
        l_deg = p1.degree;
    }
    else if (p2.degree > p1.degree)
    {
        s_deg = p1.degree;
        l_deg = p2.degree;
    }
    else
        s_deg = l_deg = p1.degree;
    Polinomial temp(l_deg);
    for (int i = 0; i <= s_deg; i++)
    {
        temp.coef[i] = p1.coef[i] - p2.coef[i];
    }
    for (int i = s_deg + 1; i <= l_deg; i++)
    {
        if (l_deg == p1.degree)
        {
            temp.coef[i] = p1.coef[i];
        }
        else if (l_deg == p2.degree)
        {
            temp.coef[i] = -(p2.coef[i]);
        }
    }
    return temp;
}

int main()
{
    int d, c;
    cout << "Enter highest degree of the first polinomial: ";
    cin >> d;
    Polinomial p1(d);
    for (int i = d; i >= 0; i--)
    {
        cout << "\nEnter coefficinet of X^" << i << " : ";
        cin >> c;
        p1.setter(c, i);
    }
    p1.display();
    cout << "\nEnter highest degree of the second polinomail: ";
    cin >> d;
    Polinomial p2(d);
    for (int i = d; i >= 0; i--)
    {
        cout << "\nEnter coefficinet of X^" << i << " : ";
        cin >> c;
        p2.setter(c, i);
    }
    Polinomial p3 = p1 + p2;
    p3.display();
    // cout<<"\n+="<<endl;
    // p1 += p2;
    // p1.display();
    cout << "\n>" << endl;
    cout << "\nP1 > P2: " << (p1 > p2) << endl;
    cout << "\nP2 > P1: " << (p2 > p1) << endl;
    cout << "\n==" << endl;
    cout << "\nP1 == P2: " << (p1 == p2) << endl;
    p1.display();
    p2.display();
    Polinomial p4 = p1 - p2;
    p4.display();
}