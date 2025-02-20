#include<iostream>
using namespace std;
int gcd(int x ,int y)
{
	///euclid's algorithm
if ( x%y==0 )
return y;
else
return gcd(y, x%y );
}

int main()
{
	int a,b ;
	cout<<"\nEnter first number : ";
	cin>>a;
	cout<<"\nEnter second number : ";
	cin>>b;
	cout<<"The greatest common divisor is : "<<gcd(a,b);
	cout<<endl<<"The least common multiple is : "<<a*b/gcd(a,b);
}
