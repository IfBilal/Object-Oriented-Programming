													//M.Bilal Tahir
													//24i-3166
													//SE-B

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;
void GenerateMatrix(int **arr,int row,int col)  //adding random values to matrix
{
	srand(time(0));
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(i==0 && j==0)
			*(*(arr+i)+j)=rand()%2;
			else
			*(*(arr+i)+j)=rand()%3-1;
		}
	}
}
int MaxScore(int** arr, int rows, int cols, int i = 0, int j = 0) // finding maximum score
{
    if (i>=rows||j>=cols||j<0||i<0||*(*(arr+i)+j)==-1) //base case so it doesnt make an invalid move or go out of bound
    return 0;
    int path[2];    // at every block there are only two moves possible either left or right and down so array of 2 length 
	    if (i%2==0)   //even row check
		{
    *path=MaxScore(arr,rows,cols,i,j+1);   //Move right
    *(path+1)=MaxScore(arr,rows,cols,i+1,j); //move down
    	} 
		else   //odd row
		{
    *path=MaxScore(arr,rows,cols,i,j-1);  //move left
    *(path+1)=MaxScore(arr,rows,cols,i+1,j); //move down
    	}
    if(*path>*(path+1))  // at every block there are two paths possible so it checks and returns the path with highest score
    	return *(*(arr+i)+j)+*path;
	else
		return *(*(arr+i)+j)+*(path+1);
}
int main()
{
int row,col;
cout<<"Enter no of row : ";  //taking Input
cin>>row;
while(row<=0)
{
	cout<<"\nInvalid\nEnter no of rows : ";
	cin>>row;
}
cout<<"Enter no of col : ";
cin>>col;
while(col<=0)
{
	cout<<"\nInvalid\nEnter no of columns : ";
	cin>>col;
}
int **arr=new int*[row];  //Generating a new array
for(int i=0;i<row;i++)
{
	*(arr+i)=new int[col];
}
GenerateMatrix(arr,row,col);  //Populating the Matrix
for(int i=0;i<row;i++)
{
	for(int j=0;j<col;j++)
	{
		cout<<setw(3)<<left<<*(*(arr+i)+j)<<"  ";   //Printing the matrix
	}
	cout<<endl;
}
cout<<"\nThe maximum score is "<<MaxScore(arr,row,col);
for(int i=0;i<row;i++)  //Deallocating the matrix
{
	delete [] *(arr+i);
}
delete []arr;

return 0;
}

