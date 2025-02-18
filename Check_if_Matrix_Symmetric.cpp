#include<iostream>
using namespace std;
bool symmetric (int ** &ptr,int row,int col)
{
	bool flag=true;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		if(ptr[i][j]!=ptr[j][i])
		flag=false;
	}
	return flag;
}
int main()
{
	int row,col;
	cout<<"Enter rows : ";
	cin>>row;
	while(row<=0)
	{
	cout<<"\nInvalid\nEnter rows : ";
	cin>>row;	
	}
	cout<<"Enter columns : ";
	cin>>col;
	while(col<=0)
	{
	cout<<"\nInvalid\nEnter columns : ";
	cin>>col;	
	}
	while(row!=col)
	{
	cout<<"\nInvalid\nEnter rows : ";
	cin>>row;
	cout<<"Enter columns : ";
	cin>>col;
	}
int **ptr= new int *[row];
for(int i=0;i<row;i++)
{
	*(ptr+i)=new int[col];
}
for(int i=0;i<row;i++)
{
	for(int j=0;j<col;j++)
	{
		cout<<"Enter element of row "<<i+1<<" col "<<j+1<<" of matrix : ";
		cin>>ptr[i][j];
	}
}
(symmetric(ptr,row,col))?cout<<"\nSymmetric":cout<<"\nNot symmetric";
return 0;
}

