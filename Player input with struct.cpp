#include<iostream>
using namespace std;
struct player{
	string name;
	string team;
	struct stats{
		int matchesPlayed;
		float averageScore;
	}stat;
	void takeInput(player &p1)
	{
		cout<<"Enter name of player : ";
		cin>>p1.name;
		cout<<"Enter name of team : ";
		cin>>p1.team;
		cout<<"Enter matches played by player : ";
		cin>>p1.stat.matchesPlayed;
		cout<<"Enter average score of player : ";
		cin>>p1.stat.averageScore;
	}
	
};
int highestAVG(player p[3])
	{
	if(p[0].stat.averageScore>=p[1].stat.averageScore && p[0].stat.averageScore>=p[2].stat.averageScore)
	return 1;
	if(p[1].stat.averageScore>=p[0].stat.averageScore && p[1].stat.averageScore>=p[2].stat.averageScore)
	return 2;
	if(p[2].stat.averageScore>=p[1].stat.averageScore && p[2].stat.averageScore>=p[0].stat.averageScore)
	return 3;	
	}	
int main()
{
	player p[3];
	for(int i=0;i<3;i++)
	p[i].takeInput(p[i]);
	cout<<"Player "<<highestAVG(p)<<" has highest avg ";

return 0;
}

