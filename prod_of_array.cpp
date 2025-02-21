#include<iostream>
using namespace std;
int productOfArray(int arr[], int n)
{
	if(n<0)
	return 1;
	
	return arr[n]*productOfArray(arr,n-1); 
}
int main()
{
int size;
cout<<"Enter size of array : ";
cin>>size;
int arr[size];
	for(int i=0;i<size;i++)
	{
		cout<<"Enter the "<<i+1<<" element of array : ";
		cin>>arr[i];
	}
	cout<<"Product of the array is : "<<productOfArray(arr,size-1);
}
