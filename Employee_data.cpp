#include<iostream>
using namespace std;
struct employee{
	string name;
	int id;
	float salary;
	void takeData()
	{
	cout<<"Enter name of employee : ";
	cin.ignore();
	getline(cin,name);
	cout<<"Enter employee id : ";
	cin>>id;
	cout<<"Enter employee salary : $";
	cin>>salary;	
	}
	void printData()
	{
		cout<<id<<','<<name<<','<<salary<<endl;
	}
};
void sortData(employee e[5])
{
	int count=0,i=0;
for(int i=0;i<5;i++)
	{
		if(i==4)
		{
			if(count==0)
			break;
			else
			{
			i=0;
			count=0;
			}
		}
		if(e[i].salary<e[i+1].salary)
		{
			employee temp;
			temp=e[i];
			e[i]=e[i+1];
			e[i+1]=temp;
			count++;
		}
	}
}
int main()
{
	employee e[5];
	for(int i=0;i<5;i++)
	{
		cout<<"Enter data for "<<i+1<<" employee : \n";
		e[i].takeData();
		system("CLS");
	}
	for(int i=0;i<5;i++)
	{
		cout<<"Data for "<<i+1<<" employee : \n";
		e[i].printData();
	}
	sortData(e);
	cout<<"\n\n\n\nData in sorted order : \n";
	for(int i=0;i<5;i++)
	{
		cout<<"Data for "<<i+1<<" employee : \n";
		e[i].printData();
	}
	
	
}
