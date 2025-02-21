#include<iostream>
using namespace std;
int reverse(int num,int rev=0)
{
	if(num==0)
	return rev;
	rev=rev*10+num%10;
	rev=reverse(num/10,rev);
}
int main()
{
	int num;
	cout<<"Enter a number : ";
	cin>>num;
	cout<<"The reversed number is : "<<reverse(num);
}

