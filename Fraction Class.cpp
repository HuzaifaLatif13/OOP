#include <iostream>
#include <iomanip>
using namespace std;
class Fraction
{
private:
    int num;
    int den;
    friend Fraction operator+(int, const Fraction &);

public:
    // overloaded constructor
    Fraction(int num = 1, int den = 1)
    {
        this->num = num;
        this->den = den;
    }
    // display
    void display()
    {
        cout << "\nThe result is: " << num << "/" << den;
    }
    // setter
    void setFraction(int num, int den)
    {
        this->num = num;
        this->den = den;
    }
    // convert to double
    double convertToDouble()
    {
        cout << "\nLets calculate the result as double." << endl;
        double result = 0.0;
        result = static_cast<double>(num) / den;
        return result;
    }
    // lets overload + operator
    Fraction operator+(const Fraction &f) const
    {
        int x = 0;
        int y = 0;
        if (this->den == f.den)
        {
            x = f.num + this->num;
            y = this->den;
        }
        else
        {
            x = ((this->num * f.den) + (this->den * f.num));
            y = (this->den * f.den);
        }
        return (Fraction(x, y));
    }
    // int +Fraction operator + (int) const
    Fraction operator+(int a) const
    {
        int x = 0;
        int y = 0;
        x = ((this->num) + (this->den * a));
        y = (this->den);
        return (Fraction(x, y));
    }
    // int +Fraction operator += (int) const
    Fraction operator+=(int a)
    {
        cout << "\nLets overload += operator with integers." << endl;
        int x = 0;
        int y = 0;
        x = ((this->num) + (this->den * a));
        y = (this->den);
        this->num = x;
        this->den = y;
        return *this;
    }

    // lets over load - operator
    const Fraction operator-(const Fraction &f)
    {
        cout << "\nlets over load - operator" << endl;
        int x = 0;
        int y = 0;
        if (this->den == f.den)
        {
            x = this->num - f.num;
            y = this->den;
        }
        else
        {
            x = (this->num * f.den) - (this->den * f.num);
            y = (this->den * f.den);
        }
        return Fraction(x, y);
    }
    // lets over load * operator
    const Fraction operator*(const Fraction &f)
    {
        cout << "\nlets over load * operator" << endl;
        int x = this->num * f.num;
        int y = this->den * f.den;
        return Fraction(x, y);
    }
    // lets over load / operator
    const Fraction operator/(const Fraction &f)
    {
        cout << "\nlets over load / operator" << endl;
        int x = 0;
        int y = 0;
        x = this->den * f.num;
        y = this->num * f.den;
        return Fraction(x, y);
    }
    // fraction-=interger
    Fraction operator-=(int a)
    {
        cout << "\nfraction-=interger" << endl;
        int x = 0;
        int y = 0;
        x = this->num - (this->den * a);
        y = this->den;
        this->num = x;
        this->den = y;
        return *this;
    }
    // fraction-interger
    Fraction operator-(int a) const
    {
        cout << "\nfraction-interger" << endl;
        int x = 0;
        int y = 0;
        x = this->num - (this->den * a);
        y = this->den;
        return (Fraction(x, y));
    }
    // fraction*interger
    Fraction operator*(int a) const
    {
        cout << "\nfraction*interger" << endl;
        int x = 0;
        int y = 0;
        x = (this->num * a);
        y = this->den;
        return (Fraction(x, y));
    }
    // fraction*=interger
    Fraction operator*=(int a)
    {
        cout << "\nfraction*=interger" << endl;
        int x = 0;
        int y = 0;
        x = (this->num * a);
        y = this->den;
        this->num = x;
        this->den = y;
        return *this;
    }
    // lets overload /=
    Fraction operator/(int a) const
    {
        cout << "\nfraction/interger" << endl;
        int x = 0;
        int y = 0;
        x = this->num;
        y = (this->den * a);
        return (Fraction(x, y));
    }
    // lets overload /=
    Fraction operator/=(int a)
    {
        cout << "\nfraction/=interger" << endl;
        int x = 0;
        int y = 0;
        x = this->num;
        y = (this->den * a);
        this->num = x;
        this->den = y;
        return *this;
    }
    // overloading +=
    Fraction operator+=(const Fraction &f)
    {
        cout << "\noverloading +=" << endl;
        int x = 0;
        int y = 0;
        if (this->den == f.den)
        {
            x = this->num + f.num;
            y = this->den;
        }
        else
        {
            x = (this->num * f.den) + (this->den * f.num);
            y = (this->den * f.den);
        }
        this->num = x;
        this->den = y;
        return *this;
    }
    // overload *=
    Fraction operator*=(const Fraction &f)
    {
        cout << "\nlets over load *= operator" << endl;
        int x = this->num * f.num;
        int y = this->den * f.den;
        this->num = x;
        this->den = y;
        return *this;
    }
    // lets over load /= operator
    const Fraction operator/=(const Fraction &f)
    {
        cout << "\nlets over load /= operator" << endl;
        int x = 0;
        int y = 0;
        x = this->den * f.num;
        y = this->num * f.den;
        this->num = x;
        this->den = y;
        return *this;
    }
};
Fraction operator+(int a, const Fraction &f)
{
    int x = 0;
    int y = 0;
    x = ((f.num) + (f.den * a));
    y = (f.den);
    return (Fraction(x, y));
}
int main()
{
    int num = 0;
    int den = 1;
    Fraction f(10, 11);
    f.display();
    cout << "\nEnter numinator: ";
    cin >> num;
    cout << "\nEnter denominator: ";
    cin >> den;
    while (den == 0)
    {
        cout << "\nDivision by zero is not allowed. Enter number again: ";
        cin >> den;
    }
    f.setFraction(num, den);
    f.display();
    double result = f.convertToDouble();
    cout << setprecision(2) << result;
    Fraction f1(2, 4);
    Fraction f2 = f + f1;
    f2.display();
    Fraction f3 = f1 + 3;
    f3.display();
    Fraction f4 = 2 + f;
    f4.display();
    Fraction f5 = f1 - f;
    f5.display();
    Fraction f6 = f1 * f;
    f6.display();
    Fraction f7 = f1 / f;
    f7.display();
    Fraction f8 = f - 3;
    f8.display();
    Fraction f9 = f * 2;
    f9.display();
    Fraction f10 = f / 2;
    f10.display();
    Fraction f11;
    f11 += f;
    f11.display();
    Fraction f12;
    f12 *= f;
    f12.display();
    Fraction f13;
    f13 /= f1;
    f13.display();
    f += 3;
    f.display();
    f5 -= 3;
    f5.display();
    f6 /= f3;
    f6.display();
}