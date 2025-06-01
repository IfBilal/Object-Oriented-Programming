#include <iostream>
using namespace std;

class HugeInteger
{
    int arr[40] = {0};

public:
    void Input()
    {
        string s;
    again:
        cout << "Enter A number of maximum 40 digits : ";
        cin >> s;
        if (s.length() > 40)
        {
            cout << "Number entered too big! " << endl;
            goto again;
        }

        for (int i = 0; i < s.length(); i++)
        {
            arr[40 - s.length() + i] = s[i] - '0';
        }
    }
    void output()
    {
        for (int i = 0; i < 40; i++)
        {
            if (arr[i] != 0)
            {
                for (int j = i; j < 40; j++)
                {
                    cout << arr[j];
                }
                cout << endl;
                break;
            }
        }
        cout << endl;
    }
    HugeInteger operator+(HugeInteger &obj)
    {
        HugeInteger temp;
        int carry = 0;
        for (int i = 39; i >= 0; i--)
        {
            int sum = arr[i] + obj.arr[i] + carry;
            temp.arr[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry > 0)
        {
            cout << "Addition not possible, Greater than 40 digits!";
            exit(0);
        }
        return temp;
    }
    bool operator==(HugeInteger &obj)
    {
        for (int i = 0; i < 40; i++)
        {
            if (arr[i] != obj.arr[i])
                return false;
        }
        return true;
    }
    bool operator<=(HugeInteger &obj)
    {
        for (int i = 0; i < 40; i++)
        {
            if (arr[i] < obj.arr[i])
                return true;
            else if (arr[i] > obj.arr[i])
                return false;
        }
        return false;
    }
    HugeInteger operator-(HugeInteger &obj)
    {
        HugeInteger temp;
        int borrow;
        if (*this <= obj)
        {
            cout << "Difference not possible!";
            exit(0);
        }

        for (int i = 39; i >= 0; i--)
        {
            int diff = arr[i] - obj.arr[i];
            if (diff < 0)
            {
                diff += 10;
                arr[i - 1]--;
            }
            temp.arr[i] = diff;
        }
        return temp;
    }
};
int main()
{
    HugeInteger A, B;
    A.Input();
    B.Input();
    // A = A + B;
    // A.output();
    A = A - B;
    A.output();
}