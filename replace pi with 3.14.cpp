#include<iostream>
using namespace std;
string replacePI(string str,string &str2,int i=0)
{
	if(i==str.length())
	{
		return str2;
	}
	if(str[i]=='p')
	{
		if(str[i+1]=='i' && i<str.length()-1)
		{
			str2+="3.14";
			return replacePI(str,str2,i+2);
		}
	}
	str2+=str[i];
	return replacePI(str,str2,i+1);
}
int main()
{
string s,p;
cout<<"Enter a string : ";
getline(cin,s);
cout<<"\nThe string after replacement is : "<<replacePI(s,p);
return 0;
}

