#include<iostream>
using namespace std;

int findChar(string str,char ch,int index=0)
{
	if(index==str.length())
	return -1;
	if(str[index]==ch)
	return index;
	return findChar(str,ch,index+1);
	
}

int main()
{
string str;
cout<<"Enter a string : ";
getline(cin,str);
char ch;
cout<<"Enter the char you want to find : ";
cin>>ch;
int pos=findChar(str,ch);
(pos==-1)?cout<<"Character not found ":cout<<"The character is at position : "<<pos;
return 0;
}

