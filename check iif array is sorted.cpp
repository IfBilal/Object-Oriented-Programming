#include<iostream>
using namespace std;
bool checkarr(int arr[],int size,int c=0)
{
	if(c==size-1)
	return 1;
	if(arr[c]>arr[c+1])
	return 0;
	else
	return checkarr(arr,size,c+1);
}
int main()
{
	int size;
	cout<<"Enter size of desired array : ";
	cin>>size;
int arr[size];
for(int i=0;i<size;i++)
{
	cout<<"Enter "<<i+1<<" element of array : ";
	cin>>arr[i];
}
int check=checkarr(arr,size);
if(check)
cout<<"Array is sorted ";
else
cout<<"Array is not sorted ";
return 0;
}

