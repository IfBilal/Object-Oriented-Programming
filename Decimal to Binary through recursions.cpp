#include<iostream>
using namespace std;

void DecToBin(int num )
{
	if(num==0)
	return ;
	DecToBin(num/2);
	cout<<num%2;
}
int main()
{
	int num;
cout<<"Enter a number : ";
cin>>num;
cout<<"The binary representation is : ";
DecToBin(num);
return 0;
}

