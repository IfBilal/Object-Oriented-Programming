									//M.Bilal Tahir
									//24i-3166
									//SE-B

#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
void delay(int j)  //for adding delay when needed
{
	for(int i=0;i<j*10;i++)
	{
		for(int k=0;k<j;k++)
		{
			
		}
	}
}
string* MakeArray(int row)   //dynamically allocating array
{
	string *arr=new string[row];
	return arr;
}
void toString(string &str,int val)  //adding the no of row at start of string
{
	if(val<10)
	str=str+char(val+'0')+' ';
	else
	{
		while(val!=0)
		{
		int num=val%10;
		str=char(num+'0')+str;
		val/=10;
		}
	}
}
void SetValue(string *arr,int row)  //assigning row no and col alphabet to each row
{
	for(int i=0;i<row;i++)
	{
		toString(*(arr+i),i+1);
		*(arr+i)=*(arr+i)+"       A        B        C        D\n";
	}	
}
void PrintData(string *arr,int row)  //printing the seats
{
	cout<<"----------------------------------------------------------------"<<endl;
	cout<<"---------------------Bus Seating System-------------------------"<<endl;
	cout<<"----------------------------------------------------------------"<<endl;
	cout<<"	";
	for(int i=0;i<row;i++)
	{
			cout<<*(arr+i);
		cout<<endl;
		cout<<"	";
	}
}
void ChangeBoard(string &str,char col)  //marking a seat as occupied
{
	bool flag=0;
	for(int i=0;i<40;i++)
	{
		if(str[i]==col)
		{
			str[i]='X';
			flag=1;
		}
	}
		if(flag==0)
			{
			cout<<"Seat Already occupied\n";
			delay(15000);
			}
	}

bool BusFull(string *arr,int row)  //check whether if bus is full
{
	int count=0;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<30;j++)
		{
		if(arr[i][j]=='X')
		count++;	
		}	
	}
	if(count==(row*4))
	return true;
}
void TakeData(string *arr,int row)  // controls main flow of the program / runs the progran
{
	do{
	int input_R;
	char input_C;
	cout<<"Enter row as -1 to exit the program \n";
	cout<<"Enter row u want to have : ";
	cin>>input_R;
	if(input_R==-1)
	{
		delete []arr;  //dealloactaing the memory
		arr=NULL;
		cout<<"Thanks for using the Program";
	exit(0);
	}
	while(input_R<=0 || input_R>row)
	{
	 cout<<"\nInvalid\nEnter row u want to have : ";
	cin>>input_R;
	if(input_R==-1)
	{
		delete []arr;	//deallocating the memory
		arr=NULL;
		cout<<"Thanks for using the Program";
	exit(0);
	}	
	}
	cout<<"Enter Col alphabet u want to have : ";
	cin>>input_C;
	while(input_C!='A' && input_C!='B' && input_C!='C' && input_C!='D')
	{
	cout<<"\nInvalid\nEnter Col alphabet u want to have : ";
	cin>>input_C;	
	}
	ChangeBoard(*(arr+(input_R-1)),input_C);
	system("CLS");
	PrintData(arr,row);
	}while(BusFull(arr,row)==0);
}
int main()
{
	int row;
cout<<"Enter no of rows in bus : ";
cin>>row;
while(row<=0)
{
	cout<<"\nInvalid\nEnter no of rows in bus : ";
	cin>>row;
}
string *arr=MakeArray(row);
SetValue(arr,row);
PrintData(arr,row);
TakeData(arr,row);
delete []arr;  //deallocating the memory
arr=NULL;
cout<<"Thanks for using the Program";
return 0;
}

