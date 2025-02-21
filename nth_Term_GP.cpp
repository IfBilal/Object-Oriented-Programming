#include<iostream>
using namespace std;
int nthTermGP(int first_term,int ratio, int terms)
{
	if (terms==1)
	return first_term;
	
	return ratio*nthTermGP(first_term,ratio,terms-1);
}
int main()
{
	cout<<"The nth term of AP is : "<<nthTermGP(2,3,4);

}
