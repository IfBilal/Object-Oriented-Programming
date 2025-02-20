#include<iostream>
#include<iomanip>
using namespace std;
struct student
{
	int exams,marks;
	int **arr;
	void examcount(student &P)
	{
		cout<<"Enter no of exams : ";
		cin>>P.exams;
		cout<<"Enter no of papers for entering marks : ";
		cin>>P.marks;
	}
	void makeArray(student &P)
	{
		arr=new int*[P.exams];
		for(int i=0;i<exams;i++)
		{
		*(arr+i)=new int[marks];	
		} 
	}
	void TakeMarks(student &P)
	{
		for(int i=0;i<P.exams;i++)
		{
			for(int j=0;j<P.marks;j++)
			{
				cout<<"Enter marks for exam "<<i+1<<" paper "<<j+1<<" : ";
				cin>>P.arr[i][j];
			}
		}
	}
	void showResult(student &P)
	{
		cout<<"The results are the following : \n"; 
		cout<<setw(10)<<left<<"Exam";
		cout<<setw(10)<<left<<"Marks";
		cout<<endl;

		for(int i=0;i<P.exams;i++)
		{
			for(int j=0;j<P.marks;j++)
			{
			cout<<setw(10)<<left<<i+1;
			cout<<setw(10)<<left<<P.arr[i][j]<<endl;	
			}
		}
	}
};

int main()
{
student ALI;
ALI.examcount(ALI);
ALI.makeArray(ALI);
ALI.TakeMarks(ALI);
ALI.showResult(ALI);
return 0;
}

