#include<iostream>
using namespace std;
int Pell(int num)
{
if(num==0 || num==1)
return num;
return 2*Pell(num-1)+Pell(num-2);	
}
int main()
{
int num;
cout<<"Enter a number : ";
cin>>num;
cout<<"The pell no is : "<<Pell(num);
return 0;
}

