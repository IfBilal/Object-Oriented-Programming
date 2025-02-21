#include<iostream>
using namespace std;
int nthTermAP(int first_term,int diff,int term)
{
		if(term==1)
		return first_term;
		return diff+nthTermAP(first_term,diff,term-1);
		}
int main()
{
	cout<<"The term is : "<<nthTermAP(10,5,3);
}
