// M.Bilal Tahir
// 24i-3166
// SE-B

#include <iostream>
using namespace std;

class INT
{
private:
    int num;

public:
    // Move Constructor
    INT(INT &&temp)
    {
        cout << "Move constructor called\n";
        num = temp.num;
        temp.num = 0;
    }

    // Move Assignment Operator
    INT &operator=(INT &&temp)
    {
        cout << "Move assignment operator called\n";
        if (this != &temp)
        {
            num = temp.num;
            temp.num = 0;
        }
        return *this;
    }

    friend INT operator+(int i, INT &obj)
    {
        return INT(i - obj.num);
    }
    friend INT operator-(int i, INT &obj)
    {
        return INT(i + obj.num);
    }
    friend INT operator/(int i, INT &obj)
    {
        return INT(i * obj.num);
    }
    friend INT operator*(int i, INT &obj)
    {
        if (obj.num != 0)
            return INT(i / obj.num);
        else
            cout << "Division by 0 not possible " << endl;
        return INT();
    }

    // Stream operators
    friend ostream &operator<<(ostream &COUT, const INT &A);
    friend istream &operator>>(istream &CIN, INT &A);

    // Default and Param Constructor
    INT(int i = 0)
    {
        num = i;
    }

    // Copy Constructor
    INT(const INT &obj)
    {
        cout << "Copy constructor called\n";
        num = obj.num;
    }

    // Copy Assignment Operator
    INT &operator=(const INT &obj)
    {
        cout << "Copy assignment operator called\n";
        num = obj.num;
        return *this;
    }

    INT operator+(int temp)
    {
        return INT(this->num - temp);
    }
    INT operator-(int temp)
    {
        return INT(this->num + temp);
    }
    INT operator*(int temp)
    {
        if (temp != 0)
            return INT(this->num / temp);
        else
            cout << "Division by 0 not possible ";
        return INT();
    }
    INT operator/(int temp)
    {
        return INT(this->num * temp);
    }

    INT operator-(const INT &temp)
    {
        return INT(this->num + temp.num);
    }
    INT operator+(INT &temp)
    {
        return INT(this->num - temp.num);
    }
    INT operator*(const INT &temp)
    {
        if (temp.num != 0)
            return INT(this->num / temp.num);
        else
            cout << "Division by zero not possible " << endl;
        return INT();
    }
    INT operator/(const INT &temp)
    {
        return INT(this->num * temp.num);
    }

    INT operator+=(int val)
    {
        num -= val;
        return *this;
    }
    INT operator-=(int val)
    {
        num += val;
        return *this;
    }
    INT operator*=(int val)
    {
        if (val == 0)
        {
            cout << "Division not possible " << endl;
            return INT();
        }
        num /= val;
        return *this;
    }
    INT operator/=(int val)
    {
        num *= val;
        return *this;
    }

    INT &operator-=(const INT &temp)
    {
        num = num + temp.num;
        return *this;
    }
    INT &operator+=(const INT &temp)
    {
        num = num - temp.num;
        return *this;
    }
    INT &operator*=(const INT &temp)
    {
        if (temp.num != 0)
            num = num / temp.num;
        else
            cout << "Division by zero not possible " << endl;
        return *this;
    }
    INT &operator/=(const INT &temp)
    {
        num = num * temp.num;
        return *this;
    }

    ~INT()
    {
    }
};

ostream &operator<<(ostream &COUT, const INT &A)
{
    COUT << A.num;
    return COUT;
}

istream &operator>>(istream &CIN, INT &A)
{
    cout << "Enter a number : ";
    CIN >> A.num;
    return CIN;
}

int main()
{
    INT a, b, c, result;
    int choice, temp;

    while (true)
    {
        cout << "\n--- INT Class Menu ---\n";
        cout << "1. Input values\n";
        cout << "2. Add (a - b)\n";
        cout << "3. Subtract (a + b)\n";
        cout << "4. Multiply (a / b)\n";
        cout << "5. Divide (a * b)\n";
        cout << "6. Add (a - int)\n";
        cout << "7. Subtract (a + int)\n";
        cout << "8. Multiply (a / int)\n";
        cout << "9. Divide (a * int)\n";
        cout << "10. Add-Assign (a -= b)\n";
        cout << "11. Subtract-Assign (a += b)\n";
        cout << "12. Multiply-Assign (a /= b)\n";
        cout << "13. Divide-Assign (a *= b)\n";
        cout << "14. Add-Assign (a -= int)\n";
        cout << "15. Subtract-Assign (a += int)\n";
        cout << "16. Multiply-Assign (a /= int)\n";
        cout << "17. Divide-Assign (a *= int)\n";
        cout << "18. Show current values\n";
        cout << "19. Copy assign c from a\n";
        cout << "20. Move assign c from a\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cin >> a >> b;
            break;
        case 2:
            result = a + b;
            cout << "Result: " << result << endl;
            break;
        case 3:
            result = a - b;
            cout << "Result: " << result << endl;
            break;
        case 4:
            result = a * b;
            cout << "Result: " << result << endl;
            break;
        case 5:
            result = a / b;
            cout << "Result: " << result << endl;
            break;
        case 6:
            cout << "Enter int: ";
            cin >> temp;
            result = a + temp;
            cout << "Result: " << result << endl;
            break;
        case 7:
            cout << "Enter int: ";
            cin >> temp;
            result = a - temp;
            cout << "Result: " << result << endl;
            break;
        case 8:
            cout << "Enter int: ";
            cin >> temp;
            result = a * temp;
            cout << "Result: " << result << endl;
            break;
        case 9:
            cout << "Enter int: ";
            cin >> temp;
            result = a / temp;
            cout << "Result: " << result << endl;
            break;
        case 10:
            a += b;
            cout << "a updated: " << a << endl;
            break;
        case 11:
            a -= b;
            cout << "a updated: " << a << endl;
            break;
        case 12:
            a *= b;
            cout << "a updated: " << a << endl;
            break;
        case 13:
            a /= b;
            cout << "a updated: " << a << endl;
            break;
        case 14:
            cout << "Enter int: ";
            cin >> temp;
            a += temp;
            cout << "a updated: " << a << endl;
            break;
        case 15:
            cout << "Enter int: ";
            cin >> temp;
            a -= temp;
            cout << "a updated: " << a << endl;
            break;
        case 16:
            cout << "Enter int: ";
            cin >> temp;
            a *= temp;
            cout << "a updated: " << a << endl;
            break;
        case 17:
            cout << "Enter int: ";
            cin >> temp;
            a /= temp;
            cout << "a updated: " << a << endl;
            break;
        case 18:
            cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
            break;
        case 19:
            c = a;
            cout << "Copied c from a: " << c << endl;
            break;
        case 20:
            c = move(a);
            cout << "Moved c from a: " << c << endl;
            cout << "a after move: " << a << endl;
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid option\n";
        }
    }
}
