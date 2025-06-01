#include <iostream>
using namespace std;
class Rational
{
private:
    int numerator;
    int denominator;

public:
    Rational(int a = 0, int b = 1)
    {
        numerator = a;
        if (b == 0)
            denominator = 1;
        else
            denominator = b;
    }
    int findHCF(int x, int y)
    {
        if (x == 0 || y == 0)
            return 1;
        if (x % y == 0)
        {
            return y;
        }
        return findHCF(y, x % y);
    }
    Rational operator+(Rational &obj)
    {
        int temp = denominator * obj.denominator;
        int temp2 = numerator * obj.denominator + obj.numerator * denominator;
        int HCF = findHCF(temp, temp2);
        return Rational(temp2 / HCF, temp / HCF);
    }
    Rational operator-(Rational &obj)
    {
        int temp = denominator * obj.denominator;
        int temp2 = numerator * obj.denominator - obj.numerator * denominator;
        int HCF = findHCF(temp, temp2);
        return Rational(temp2 / HCF, temp / HCF);
    }
    Rational operator*(Rational &obj)
    {
        int temp, temp2, HCF = 1;
        temp = denominator * obj.denominator;
        temp2 = numerator * obj.numerator;
        HCF = findHCF(temp, temp2);
        return Rational(temp2 / HCF, temp / HCF);
    }
    Rational operator/(Rational &obj)
    {
        if (obj.numerator == 0)
        {
            cout << "Division not possible ";
            return Rational();
        }
        int temp, temp2;
        temp = denominator * obj.numerator;
        temp2 = numerator * obj.denominator;
        int HCF = findHCF(temp, temp2);
        return Rational(temp2 / HCF, temp / HCF);
    }
    void display()
    {
        if (numerator != 0)
            cout << numerator << " / " << denominator << endl
                 << endl;
        else
            cout << numerator << endl;
    }
    void displayFloat()
    {
        float temp = numerator * 1.0 / denominator * 1.0;
        cout << temp << endl;
    }
};
int main()
{
    Rational first(2, 4), second(3, 6);
    first = first + second;
    first.displayFloat();
    first = first - second;
    first.displayFloat();
    first = first * second;
    first.displayFloat();
    first = first / second;
    first.displayFloat();
}