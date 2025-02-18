#include<iostream>
using namespace std;
bool elfish(char word[10], char elf[4], int index)
{
	if(index==10)
	{
		if(elf[0]==' ' && elf[1]==' ' && elf[2]==' ')
		return true;
		else
		return false;
	}
	if(word[index]==elf[0] )
	elf[0]=' ';
	if(word[index]==elf[1] )
	elf[1]=' ';
	if(word[index]==elf[2] )
	elf[2]=' ';
	return elfish(word,elf,index+1);
}
int main()
{
char word[10],elf[4]="elf";
cout<<"Enter string : ";
cin>>word;
(elfish(word,elf,0))?cout<<"Elfish ":cout<<"Not elfish";
return 0;
}

