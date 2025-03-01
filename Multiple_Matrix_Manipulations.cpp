														//M.Bilal Tahir
														//i24-3166
														//SE_B

#include<iostream>
#include<iomanip>
#define row 3
#define col 1
using namespace std;
int** MakeArray()    //Dynamically allocating array
{
	int** A=new int*[row];
	for(int i=0;i<row;i++)
	{
		*(A+i)=new int[col];
	}
	return A;
}
void DeleteArray(int **A)  //deallocating the arrays
{
	for(int i=0;i<row;i++)
	{
		delete[] *(A+i);
		*(A+i)=NULL;
	}
	delete[] A;
	A=NULL;
}
void CheckEqualSumArrays(int **A1 , int **A2 , int **A3)
{
	bool flag=1;    //keeping a boolean value so we can make condition false whenever any corresponding value is not equal after sum
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(*(*(A1+i)+j)+*(*(A2+i)+j)!=*(*(A3+i)+j))  //checking sum of two matrices with other matrix
			flag=0;
		}
	}
	if(flag==1)
	cout<<"\nSUM of First matrix and second matrix is equal to third matrix \n";  //If equal then prints
	flag=1;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(*(*(A1+i)+j)+*(*(A3+i)+j)!=*(*(A2+i)+j))
			flag=0;
		}
	}
	if(flag==1)
	cout<<"\nSUM of First matrix and third matrix is equal to second matrix \n";
	flag=1;
		for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(*(*(A3+i)+j)+*(*(A2+i)+j)!=*(*(A1+i)+j))
			flag=0;
		}
	}
	if(flag==1)
	cout<<"\nSUM of third matrix and second matrix is equal to first matrix \n";
}
void CheckDifferentArrays(int **A1, int **A2 , int **A3 )   //Finding difference with more possibilities bcz A-B is != B-A
{
	bool flag=1;   //bool value to keep check whther difference is equal or not
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(*(*(A1+i)+j)-*(*(A2+i)+j)!=*(*(A3+i)+j))   //checking whether corresponding entries are equal after difference 
			flag=0;
		}
	}
	if(flag==1)
	cout<<"\nDifference of First matrix and second matrix is equal to third matrix \n";
	flag=1;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(*(*(A1+i)+j)-*(*(A3+i)+j)!=*(*(A2+i)+j))
			flag=0;
		}
	}
	if(flag==1)
	cout<<"\nDifference of First matrix and third matrix is equal to second matrix \n";  //If equal then prints 
	//Same for all possibilities
	flag=1;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(*(*(A2+i)+j)-*(*(A1+i)+j)!=*(*(A3+i)+j))
			flag=0;
		}
	}
	if(flag==1)
	cout<<"\nDifference of second matrix and first matrix is equal to third matrix \n";
	flag=1;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(*(*(A2+i)+j)-*(*(A3+i)+j)!=*(*(A1+i)+j))
			flag=0;
		}
	}
	if(flag==1)
	cout<<"\nDifference of second matrix and third matrix is equal to first matrix \n";
	flag=1;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(*(*(A3+i)+j)-*(*(A1+i)+j)!=*(*(A2+i)+j))
			flag=0;
		}
	}
	if(flag==1)
	cout<<"\nDifference of Third matrix and First matrix is equal to second matrix \n";
	
	flag=1;
		for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(*(*(A3+i)+j)-*(*(A2+i)+j)!=*(*(A1+i)+j))
			flag=0;
		}
	}
	if(flag==1)
	cout<<"\nDifference of third matrix and second matrix is equal to first matrix \n";
}
void CheckEqualArrays(int **A1 , int **A2, int **A3)
{
	bool flag=1;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(*(*(A1+i)+j)!=*(*(A2+i)+j))
			flag=0;
		}
	}
	if(flag==1)
	cout<<"\nFirst and second matrices are Equal \n";
	flag=1;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(*(*(A1+i)+j)!=*(*(A3+i)+j))
			flag=0;
		}
	}
	if(flag==1)
	cout<<"\nFirst and Third matrices are Equal \n";
	flag=1;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(*(*(A3+i)+j)!=*(*(A2+i)+j))
			flag=0;
		}
	}
	if(flag==1)
	cout<<"\nSecond and Third matrices are Equal \n";	
}
void SwapCols(int **A,int rows,int cols)    //reversing the 2D array like in palindrome so it becomes rotated
{
	int start=0,end=cols-1;
	while(start<=end)
	{
		for(int i=0;i<rows;i++)
		{
			swap(*(*(A+i)+start),*(*(A+i)+end));
		}
		start++;
		end--;
	}
}
void RotateArrays(int **A1 , int **A2 , int **A3 )  //generating a new 2D array for rotation as rotated array can have different dimensions in a non square matrix
{
	int** A=new int*[col];  //generating new matrix with idfferent dimensions
	for(int i=0;i<col;i++)
	{
		*(A+i)=new int[row];
	}
	for(int i=0;i<row;i++) //Transpose of the Matrix
	{
		for(int j=0;j<col;j++)
		{
		*(*(A+j)+i)=*(*(A1+i)+j);
		}
	}
	SwapCols(A,col,row);
	cout<<"\nThe rotated matrix of first matrix is : \n";
	for(int i=0;i<col;i++)
	{
		for(int j=0;j<row;j++)
		{
			cout<<setw(4)<<left<<*(*(A+i)+j);
		}
		cout<<endl;
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
		*(*(A+j)+i)=*(*(A2+i)+j);
		}
	}
	SwapCols(A,col,row);
	cout<<"The rotated matrix of second matrix is : \n";
	for(int i=0;i<col;i++)
	{
		for(int j=0;j<row;j++)
		{
			cout<<setw(4)<<left<<*(*(A+i)+j);
		}
		cout<<endl;
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
		*(*(A+j)+i)=*(*(A3+i)+j);
		}
	}
	SwapCols(A,col,row);
	cout<<"The rotated matrix of Third matrix is : \n";
	for(int i=0;i<col;i++)
	{
		for(int j=0;j<row;j++)
		{
			cout<<setw(4)<<left<<*(*(A+i)+j);
		}
		cout<<endl;
	}
	for(int i=0;i<col;i++)
	{
		delete[] *(A+i);
		*(A+i)=NULL;
	}
	delete[] A;
	A=NULL;
}
void FindSameRows(int **A1 , int **A2 , int **A3)  //Find same rows in all matrices
{
//	bool flag=1;
//	for(int i=0;i<row;i++)
//	{
//		for(int j=0;j<col;j++)
//		{
//			if(*(*(A1+i)+j) != *(*(A2+i)+j) || *(*(A1+i)+j) != *(*(A3+i)+j))
//			flag=0;
//		}
//		if(flag==1)
//		cout<<"Row "<<i+1<<" of all matrices are same\n";
//	}

	int *temp=new int[col];  //Generating a new array for storing a row of matrix and comparing it with other rows of the same matrix 
	bool flag=1;  //a boolean value to keep check whether a row matches with the other row or not
	for(int i=0;i<row;i++)
	{
		flag=1;
		for(int j=0;j<col;j++)
		{
		*(temp+j)=*(*(A1+i)+j);  //Assigning a row of the matrix to the new generated array
		}
		for(int k=i+1;k<row;k++)
		{
			flag=1;
			for(int p=0;p<col;p++)
			{
				if(*(temp+p)!=*(*(A1+k)+p))  //matching the row with oother rows
				flag=0;
			}
			if(flag==1)
			cout<<"\nIn Matrix 1, "<<i+1<<" and "<<k+1<<" rows are same ";  //if matches then prints that they are same and then move to next row
		}
	}
	//same for second matrix and then third matrix
	for(int i=0;i<row;i++)
	{
		flag=1;
		for(int j=0;j<col;j++)
		{
		*(temp+j)=*(*(A2+i)+j);
		}
		for(int k=i+1;k<row;k++)
		{
			flag=1;
			for(int p=0;p<col;p++)
			{
				if(*(temp+p)!=*(*(A2+k)+p))
				flag=0;
			}
			if(flag==1)
			cout<<"\nIn Matrix 2, "<<i+1<<" and "<<k+1<<" rows are same ";
		}
	}
	for(int i=0;i<row;i++)
	{
		flag=1;
		for(int j=0;j<col;j++)
		{
		*(temp+j)=*(*(A3+i)+j);
		}
		for(int k=i+1;k<row;k++)
		{
			flag=1;
			for(int p=0;p<col;p++)
			{
				if(*(temp+p)!=*(*(A3+k)+p))
				flag=0;
			}
			if(flag==1)
			cout<<"\nIn Matrix 3, "<<i+1<<" and "<<k+1<<" rows are same ";
		}
	}
	delete[] temp;	
}
int main()
{
	int **A1=MakeArray();
	int **A2=MakeArray();
	int **A3=MakeArray();
	for(int i=0;i<row;i++)    //Taking matrix elemenyts as input
	{
		for(int j=0;j<col;j++)
		{
		cout<<"Enter row "<<i+1<<" col "<<j+1<<" for first matrix : ";
		cin>>*(*(A1+i)+j);
		}
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
		cout<<"Enter row "<<i+1<<" col "<<j+1<<" for second matrix : ";
		cin>>*(*(A2+i)+j);
		}
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
		cout<<"Enter row "<<i+1<<" col "<<j+1<<" for third matrix : ";
		cin>>*(*(A3+i)+j);
		}
	}
	CheckEqualSumArrays(A1,A2,A3);
	CheckDifferentArrays(A1,A2,A3);
	CheckEqualArrays(A1,A2,A3);
	FindSameRows(A1,A2,A3);
	RotateArrays(A1,A2,A3);
	DeleteArray(A1);
	DeleteArray(A2);
	DeleteArray(A3);
return 0;
}

