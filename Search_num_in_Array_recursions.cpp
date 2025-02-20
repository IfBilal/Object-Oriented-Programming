#include<iostream>
using namespace std;
bool findNum(int arr[10],int num,int start=0,int end=9)
{
	if(start>=end)
	return false;
	if(arr[start]==num || arr[end]==num)
	return true ;
	else
	return findNum(arr,num,start+1,end-1);
}
int main()
{
int arr[10];
for(int i=0;i<10;i++)
{
cout<<"Enter "<<i+1<<" no of array : ";
cin>>arr[i];
}
int num;
cout<<"Enter no to find : ";
cin>>num;
int check=findNum(arr,num);
(check)?cout<<"\nNumber is present ":cout<<"\nNumber not found";
return 0;
}

