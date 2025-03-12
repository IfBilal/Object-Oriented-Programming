//M.Bilal Tahir
//24i-3166
//it takes no of stairs as input and returns no of possible ways a person can reach the top , he can take 1 or 2 or 3 steps
#include<iostream>
using namespace std;
int Dungeon(int stairs,int &count,int start=0)
{
	if(stairs<=0)
	return 0;
	if(start==stairs)
	{
		count+=1;
		return count;
	}
	if(start>stairs)
	return count;
	
	Dungeon(stairs,count,start+1);
	Dungeon(stairs,count,start+2);
	Dungeon(stairs,count,start+3);
	return count;
}
int main()
{
	int count=0;
cout<<"Possible paths are : "<<Dungeon(4,count);
return 0;
}
	
