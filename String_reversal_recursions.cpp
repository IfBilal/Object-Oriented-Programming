#include<iostream>
using namespace std;
string reverse(string &s,int length,int a=0)
{
	if(a>=length)
	return s;
	char temp;
	temp=s[a];
	s[a]=s[length];
	s[length]=temp;
	return reverse(s,length-1,a+1);
}
int main()
{
string s;
cout<<"Enter a string : ";
getline(cin,s);
int length=s.length();
cout<<"The reversed  string is : "<<reverse(s,length-1);
return 0;
}
