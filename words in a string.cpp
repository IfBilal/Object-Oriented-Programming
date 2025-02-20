#include<iostream>
using namespace std;
int words(string str,int position=0,int count=0,string temp="")
{
	
	if(position==str.length())
	{
		if(temp[0]!=' ')
		cout<<"Found : "<<temp<<endl;
		if(str[0]==' ')
		return count;
		else if(str[0]!=' ')
		return count+1;
	}
	if(str[position]==32 && str[position+1]!=32 && str[position+1]!='\0' ) 
	{
		if(temp[0]!=' ')
		cout<<"Found : "<<temp<<endl;
		return words(str,position+1,count+1,"\0");
}
		if(str[position]==32 && str[position+1]!=32 && str[position+1]!='\0' )
	{
		if(temp[0]!=' ')
		cout<<"Found : "<<temp<<endl;
	return words(str,position+1,count+1,"\0");
	}
		temp=temp+str[position];
		return words(str,position+1,count,temp);
}
int main()
{
string str;
cout<<"Enter a string : ";
getline(cin,str);
cout<<"The no of words in sentence are : "<<words(str);
return 0;
}

