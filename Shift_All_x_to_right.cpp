#include<iostream>
using namespace std;
//shifts all x to right in string
void shiftback(string &str, int start, int length)
{
	
	for(start;start<length;start++)	{
		str[start]=str[start+1];
	}
}
string AsideX(string &str,int length,int start=0)
{
	if(start>=length)
	return str;
	if(str[start]=='x')
	{
		shiftback(str,start,str.length()-1);
		str[length]='x';
		AsideX(str,length-1,start);
	}
	else
	AsideX(str,length,start+1);
	return str;
}
int main()
{
string s;
cout<<"Enter string : ";
getline(cin,s);
cout<<endl<<AsideX(s,s.length()-1);
return 0;
}
