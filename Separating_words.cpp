#include<iostream>
//This code has a string arr as dictionary and a word without spaces and it prints 1 if the word can be fully divided into the string array otherwise prints 0
using namespace std;
void checkWord(string &str,string dict[],int dictsize,int start=0)
{
	if(start==dictsize)
	return;
	if(str==dict[start])
	str="\0";
	checkWord(str,dict,dictsize,start+1);
}
bool wordBreakHelper(string str,string dict[],int dictsize,int index,string temp="")
{
	if(index==str.size())
	{
		if(temp.empty())
		return true;
		else
		return false;
	}
	temp=temp+str[index];
	checkWord(temp,dict,dictsize);
	return wordBreakHelper(str,dict,dictsize,index+1,temp);
	
}
int main() {
    string dict[] = {"small","experience"};
    int size = sizeof(dict) / sizeof(dict[0]);

    cout << wordBreakHelper("smallexperience", dict,size, 0) << endl;
}
