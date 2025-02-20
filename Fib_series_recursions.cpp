#include<iostream>
using namespace std;
int fib(int num)
{
	if(num==0 || num==1)
	return num;
	return fib(num-2)+fib(num-1);
}

int main()
{
	int num;
cout<<"Enter no for fibonacci series : ";
cin>>num;
cout<<fib(num);
return 0;
}
