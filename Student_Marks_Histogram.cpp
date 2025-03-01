														//M.Bilal Tahir
														//24i-3166
														//SE-B


#include<iostream>
#include<iomanip>
using namespace std;
//we would make our own Vector in whiich there would be an array of capacity 1 at the beginning, capacity is the size of array and the size is the no elements stored in the array 
//when we add an element we will increase the size by one and whenever the size becomes equal to capacity we generate another array of capacity double than the previous array
//and copy all the elements from previous array to new array and then the pointer of previous array starts to point the new array.Previous array is deleted

class Array
{
public:
	float *arr=new float[1];  // A float array to store student marks
	int size=0;
	int capacity=1;
	
	void add(float val)  //Function to add a new element in the array
	{
		if(size==capacity)  //when size equal to capacity then form new array with double capacity
		{
			capacity=capacity*2;
			float *arr2=new float[capacity];
			for(int i=0;i<size;i++)
			{
				*(arr2+i)=*(arr+i);
			}
			delete []arr;
			arr=NULL;
			arr=arr2;
		}
		arr[size]=val;  //add marks in the array and increase size by 1
		size++;
	}
	void PrintHistogram(float **ptr)  //prints the histogram
	{
		float max=0;
		for(int i=0;i<size;i++)  //finds the maximum frequency
		{
			if(max<*(*(ptr+i)+1))
			{
				max=*(*(ptr+i)+1);
			}
		}
		for(int i=max;i>0;i--)  //prints the histogram
		{
			cout<<endl;
			cout<<setw(5)<<left<<i;
			cout<<" | ";
			for(int j=0;j<size;j++)
			{
				if(*(*(ptr+j))!=-1)
				if(*(*(ptr+j)+1)>=i)
				cout<<setw(5)<<" * ";
				else
				cout<<setw(5)<<"   ";
			}
			cout<<endl;
		}
		cout<<"      _________________________________________________"<<endl<<"         ";
		for(int i=0;i<size;i++)
		{
			if(*(*(ptr+i))!=-1)
		cout<<setw(5)<<left<<*(*(ptr+i));
		}	
	}
	
	float** PrintFrequency()
	{
		bool flag=1;
		int count=0;
		float **ptr=new float* [size];  //generate a 2D array in which one column will store all values without repitition and the second column will store its frequency
		for(int i=0;i<size;i++)
		{
			*(ptr+i)=new float[2]; 
		}
		for(int i=0;i<size;i++)  //assign all values by -1
		{
			*(*(ptr+i))=-1;
		}
		for(int i=0;i<size;i++)  //copy all elements from 1D array to first column of 2D array without repitition
		{
			flag=1;
			for(int j=0;j<size;j++)
			{
				if(i!=j)
				{
				if(*(*(ptr+j))==*(arr+i))
				flag=0;
				}
			}
			if(flag==1)  //If a number repeats it doesnt add it again
			{
			*(*(ptr+count))=*(arr+i);
			count++;
			}
		}
	
		int counter=0;
		for(int i=0;i<size;i++)  //counts the frquency of each marks and assigns it to the second column of the 2D array 
		{
			for(int j=0;j<size;j++)
			if(*(*(ptr+i))==*(arr+j))
			counter++;
			*(*(ptr+i)+1)=counter;
			counter=0;
		}
		for(int i=0;i<size;i++)  //Prints the frequency
		{
			if(*(*(ptr+i))!=-1)
			cout<<"\nThe frequency of "<<*(*(ptr+i))<<" is : "<<*(*(ptr+i)+1);
		}
		
		return ptr;
		}
	void deleteArray()  //delete the 1D array
	{
		delete[] arr;
	}

	
};
int main()
{
Array A;
float num=0;
while(true)
{
	cout<<"Enter Marks : ";
	cin>>num;
	if(num==-1)
	break;
	while(num<0)
	{
	cout<<"\nInvalid\nEnter Marks : ";
	cin>>num;
	if(num==-1)
	break;
	}
	if(num==-1)
	break;
	A.add(num);
}
float **ptr=A.PrintFrequency();
A.deleteArray();
A.PrintHistogram(ptr);
for(int i=0;i<A.size;i++)  //deletes the 2D array
		{
			delete[] *(ptr+i); 
		}
		
		delete[] ptr;
return 0;
}

