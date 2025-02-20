#include <iostream>
using namespace std;
//finds no of all unique paths to move from left top to right bottom by only moving down and right
int uniquePaths(int m, int n) {
    if (m == 1 || n == 1) 
	return 1;
    return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
}

int main() {
    cout << uniquePaths(5, 5) << endl;
}
