#include<iostream>
using namespace std;
void star(int n)
{
	if(n==0)
	return ;
	cout<<"*";
	star(n-1);
}
void triangle(int n)
{
	if(n==0)
	return ;
	triangle(n-1);
	star(n);
	cout<<endl;
}
int main()
{
int n;
cout<<"Enter no of lines : ";
cin>>n;
triangle(n);
return 0;
}

