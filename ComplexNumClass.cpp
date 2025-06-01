#include <iostream>
using namespace std;
class complex
{
private:
    double realPart;
    double imaginaryPart;

public:
    complex(double a = 0, double b = 0)
    {
        realPart = a;
        imaginaryPart = b;
    }
    complex add(complex first, complex second)
    {
        return complex(first.realPart + second.realPart, first.imaginaryPart + second.imaginaryPart);
    }
    complex subtract(complex first, complex second)
    {
        return complex(first.realPart - second.realPart, first.imaginaryPart - second.imaginaryPart);
    }
    complex operator+(complex first)
    {
        return complex(first.realPart + realPart, first.imaginaryPart + imaginaryPart);
    }
    complex operator-(complex first)
    {
        return complex(realPart - first.realPart, imaginaryPart - first.imaginaryPart);
    }
    complex &operator+=(complex first)
    {
        realPart += first.realPart;
        imaginaryPart += first.imaginaryPart;
        return *this;
    }
    complex &operator-=(complex first)
    {
        realPart -= first.realPart;
        imaginaryPart -= first.imaginaryPart;
        return *this;
    }
    void display()
    {
        cout << "( " << realPart << " , " << imaginaryPart << " ) " << endl;
    }
};
int main()
{
    complex A(2.4, 3.6), B(6.1, 8.2);
    A.display();
    B.display();
    A = A - B;
    A.display();
    A = A.subtract(A, B);
    A.display();
    A += B;
    A.display();
    A -= B;
    A.display();
}