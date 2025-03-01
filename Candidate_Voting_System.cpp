										//M.Bilal Tahir
										//24i-3166
										//SE-B

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
void TakeInput(string *name,int *votes,int num)    //inputs marks and no of votes from user
{
	for(int i=0;i<num;i++)
	{
		cout<<"Enter name of candidate "<<i+1<<" : ";
		cin>>*(name+i);
		cout<<"Enter votes of candidate "<<i+1<<" : ";
		cin>>*(votes+i);
		while(*(votes+i)<0)
		{
		cout<<"\nInvalid\nEnter votes of candidate "<<i+1<<" : ";
		cin>>*(votes+i);	
		}
	}
}
void FindPercent(string *name,int *votes,float *perc,int num)  //find percentage of votes of each candidate
{
	int total;
	for(int i=0;i<num;i++)  //find total votes
	{
		total+=votes[i];
	}
	for(int i=0;i<num;i++)
	{
		*(perc+i)=(*(votes+i)*100.0)/(total);
	}
}
void PrintResult(string *name,int *votes,float *perc,int num)  //prints final results
{
	cout<<left<<setw(15)<<"Candidate";
	cout<<left<<setw(10)<<"Votes";
	cout<<left<<setw(10)<<setprecision(2)<<fixed<<"% of Total Votes"<<endl;
	for(int i=0;i<num;i++)
	{
		cout<<left<<setw(15)<<*(name+i);
		cout<<left<<setw(10)<<*(votes+i);
		cout<<left<<setw(10)<<*(perc+i)<<endl;
	}
	int total;
	for(int i=0;i<num;i++)
	{
		total+=votes[i];
	}
	cout<<left<<setw(15)<<"Total";
	cout<<left<<setw(10)<<total;
}
void FindWinner(string *name,int *votes,int num)  //finds the winner
{
	int max=0;
	bool tie=0;
	for(int i=0;i<num;i++)
	{
		if(*(votes+max)<*(votes+i))
		max=i;
	}
	for(int i=0;i<num;i++)  //check if there is a tie
	{
		if(i!=max)
		if(*(votes+max)==*(votes+i))
		{
		tie=1;	
		}
	}
	if(tie==1)  //Prints the names between which there is a tie
	{
	cout<<"\nThe elections is a tie beteween : ";
		for(int i=0;i<num;i++)
		{
		if(*(votes+max)==*(votes+i))
		cout<<*(name+i)<<" , ";	
		}
		cout<<"\b\b ";
	}
	else
	cout<<"\nThe winner of the local elections is : "<<name[max];  //if no tie than print the winner
}
int main()
{
	int cand;
cout<<"Enter no of candidates : ";
cin>>cand;
	while(cand<=0)
	{
	cout<<"Invalid\nEnter no of candidates : ";
	cin>>cand;
	}
	string *name=new string[cand];
	int *votes=new int[cand];
	float *perc=new float[cand];
	TakeInput(name,votes,cand);
	FindPercent(name,votes,perc,cand);
	PrintResult(name,votes,perc,cand);
	FindWinner(name,votes,cand);
	delete[] name;
	delete[] votes;
	delete[] perc;
	name=NULL;
	votes=NULL;
	perc=NULL;
return 0;
}

