#include<iostream>
using namespace std;

void bulk(int &amount)
{
	amount=amount*0.8;
}
void new_user(int &amount)
{
	amount=amount*0.7;
}
void holidays(int &amount)
{
	amount=amount*0.5;
}
void final_amount(int &amount,void (*operation)(int &))
{
	operation(amount);
}
int main()
{
	int option,count;
	int amount=0;
	
do{
cout<<"Enter 1 to buy juice 10$\nEnter 2 to buy milk 15$\nEnter 3 to buy lays 20$\nEnter 0 to exit\n";
cin>>option;
while(option<0 || option>3)
{
	cout<<"\nInvalid\nTry again ";
	cin>>option;
}
count++;
switch(option)
	{
	case 1:
		amount+=10;
	break;
	case 2:
		amount+=15;
	break;
	case 3:
		amount+=20;
	break;
	}
}
while(option!=0);
int user,holiday;
cout<<"Enter 1 if ur a new user else enter 0 : ";
cin>>user;
while(user!=0 && user!=1)
{
cout<<"\nInvalid\nEnter 1 if ur a new user else enter 0 : ";
cin>>user;	
}
cout<<"Enter 1 if today is holiday else enter 0 : ";
cin>>holiday;
while(holiday!=0 && holiday!=1)
{
cout<<"\nInvalid\nEnter 1 if today is holiday else enter 0 : ";
cin>>holiday;	
}
if(user==1)
final_amount(amount,new_user);
if(count>1)
final_amount(amount,bulk);
if(holiday==1)
final_amount(amount,holidays);
cout<<"\nThe final price is : "<<amount;
return 0;
}

