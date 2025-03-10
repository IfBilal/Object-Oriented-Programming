#include <iostream>
#define N 4
using namespace std;

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < row; i++) 
	{  
        if (board[i][col])
			return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) 
	{
	    if (board[i][j]) 
			return false;
    }
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) 
	{  
        if (board[i][j]) 
			return false;
    }
	return true; 
}

bool solveNQueens(int board[N][N], int col=0,int row=0) {
	if(row==N)
		return 1;
	if(col==N)
		return 0;
	if(isSafe(board,row,col)){
		board[row][col]=1;
		if(solveNQueens(board,0,row+1))
			return true;
		board[row][col]=0;
			return solveNQueens(board,col+1,row);
	}
	else
		return solveNQueens(board,col+1,row);  
}

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
        cout << (board[i][j] ? "Q " : ". ");
        }
        cout << "\n";
    }
}

int main() {
    int board[N][N] = {0};
    
    if (solveNQueens(board)) 
        printSolution(board);
	else 
        cout << "No solution exists" << endl;
    return 0;
}
