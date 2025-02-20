#include<iostream>
using namespace std;
void Hanoi(int n,int source=1,int help=2,int destination=3)
{
if(n==1)
{
	cout<<"\nMove ring no. "<<n<<" from "<<source <<" to "<<destination<<endl;
	return ;
}
Hanoi(n-1,source,destination,help);
cout<<"Move ring no. "<<n<<" from "<<source <<" to "<<destination<<endl;
Hanoi(n-1,help,source,destination);
}

int main()
{
	int n;
cout<<"Enter no of rings : ";
cin>>n;
Hanoi(n);
return 0;
}
