#include<iostream>
using namespace std;

int power (int a, int b)
{
if(b==0)
return 1;
return a*power(a,b-1);
}

int main()
{
	int a,b;
	cout<<"Enter number : ";
	cin>>a;
	cout<<"\nEnter power : ";
	cin>>b;
	cout<<"The answer is : "<<power(a,b);
}
