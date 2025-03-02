#include<iostream>
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
    string dict[] = {"apple","pen"};
    int size = sizeof(dict) / sizeof(dict[0]);

    cout << wordBreakHelper("applepenapple", dict,size, 0) << endl;
}


