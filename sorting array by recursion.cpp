#include<iostream>
using namespace std;

void SortArray(int arr[],int num,int i=0,int a=0)
{
	if(i==num-1 && a==0)
	return ;
	else if(i==num-1)
	{
	i=0;
	a=0;
	}
	if(arr[i]>arr[i+1])
	{
		int temp;
		temp=arr[i];
		arr[i]=arr[i+1];
		arr[i+1]=temp;	
		a++;	
	}
	return SortArray(arr,num,i+1,a);	
}
int main()
{
	int num;
cout<<"Enter no of elements in array : ";
cin>>num;
int arr[num];
for(int i=0;i<num;i++)
{
	cout<<"Enter element "<<i+1<<" of array : ";
	cin>>arr[i];
}
SortArray(arr,num);
cout<<"The sorted array is : ";
for(int i=0;i<num;i++)
{
	cout<<arr[i]<<"  ";
}

return 0;
}

