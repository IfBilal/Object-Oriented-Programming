#include<iostream>
using namespace std;
//bool powerof5(float num)
//{
//	if(num<2)
//	{
//		if(num==1)
//		return true;
//		else 
//		return false;
//	}
//	return powerof5(num/5);
//}


//with integer parameter
bool powerof5(int num)
{
	if(num==1)
	return true;
	if(num==0 or num%5!=0)
	return false;
	return powerof5(num/5);
}
int main()
{
float num;
cout<<"Enter a number : ";
cin>>num;
(powerof5(num))?cout<<"Power of 5 ":cout<<"Not a power of 5";
return 0;
}

