#include <iostream>
using namespace std;

class A
{
private:
    int x = 6;
    int y = 1;
    int z = 2;
    int arr[10];

public:
friend A operator+(int,A);
friend istream& operator>>(istream& CIN,A& obj);
friend ostream& operator<<(ostream&,A&);
A()
{
    for(int i=0;i<10;i++)
    {
        arr[i]=i+1;
    }
}
    A operator+(A &obj)
    {
        A temp;
        temp.x = this->x + obj.x;
        temp.y = this->y + obj.y;
        temp.z = this->z + obj.z;
        return temp;
    }
    A operator-(A &obj)
    {
        A temp;
        temp.x = this->x - obj.x;
        temp.y = this->y - obj.y;
        temp.z = this->z - obj.z;
        return temp;
    }
    A operator*(A &obj)
    {
        A temp;
        temp.x = this->x * obj.x;
        temp.y = this->y * obj.y;
        temp.z = this->z * obj.z;
        return temp;
    }
    A operator/(A &obj)
    {
        A temp;
        temp.x = this->x / obj.x;
        temp.y = this->y / obj.y;
        temp.z = this->z / obj.z;
        return temp;
    }
    A operator%(A &obj)
    {
        A temp;
        temp.x = this->x % obj.x;
        temp.y = this->y % obj.y;
        temp.z = this->z % obj.z;
        return temp;
    }
    A operator+(int a)
    {
        A temp;
        temp.x=x+5;
        temp.y=y+5;
        temp.z=z+5;
        return temp;
    }
    bool operator==(A temp)
    {
        bool check;
        check=( x==temp.x &&y==temp.y && z==temp.z);
        return check;
    }
    void operator+=(int a)
    {
        x=x+a;
        y=y+a;
        z=z+a;
    }
    A& operator++()
    {
        x++;
        y++;
        z++;
        return *this;
    }
    A operator++(int)
    {
        A temp;
        temp.x=x;
        temp.y=y;
        temp.z=z;
        x++;
        y++;
        z++;
        return temp;
    }
    int operator[](int index)
    {
        if(index>9 || index<0)
        return -1;
        return arr[index];
    }
    A operator()(int x,int y,int z)
    {
        A temp;
        temp.x=x;
        temp.y=y;
        temp.z=z;
        return temp;
    }
    void display()
    {
        cout << x << "  " << y << "  " << z << endl;
    }
};

A operator+(int a , A temporary)
{
    A temp;
    temp.x=temporary.x+a;
    temp.y=temporary.y+a;
    temp.z=temporary.z+a;
    return temp;
}

istream& operator>>(istream& CIN , A& obj)
{
cout<<"Enter x : ";
CIN>>obj.x;
cout<<"Enter y : ";
CIN>>obj.y;
cout<<"Enter z : ";
CIN>>obj.z;
return CIN;
}
ostream& operator<<(ostream& COUT , A& obj)
{
COUT<<obj.x<<"   "<<obj.y<<"    "<<obj.z<<endl;  
return COUT;
}
int main()
{
    A a1, a2, a3;
    a3.display();
    a3 = a1 + a2;
    a3.display();
    a3 = a1 - a2;
    a3.display();
    a3 = a1 * a2;
    a3.display();
    a3 = a1 / a2;
    a3.display();
    a3 = a1 % a2;
    a3.display();
    a3+=10;
    a3.display();
    bool res1 = (a1 == a2);
    cout<<res1;
    a2=++a1;
    a1.display();
    a2.display();
    a2=a1++;
    a1.display();
    a2.display();
     int val = a1[10];
    cout<<val;
    cout << a1;
    cin >> a1;
    a3 = a1(1,5,9);
    a3.display();
    cin>>a1;
    cout<<a1;
}