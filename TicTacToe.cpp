#include <iostream>
using namespace std;
class TicTacToe
{
    int arr[3][3];

public:
    TicTacToe()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                arr[i][j] = 0;
            }
        }
    }
    void display()
    {
        cout << "=======================Tic Tac Toe====================== \n\n";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j == 2)
                    cout << arr[i][j];
                else
                    cout << arr[i][j] << "  |  ";
            }
            cout << endl;
        }
    }
    bool winner(int a)
    {
        bool winner = false;
        int count = 0;
        for (int i = 0; i < 3; i++)
        {
            count = 0;
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] == a)
                    count++;
            }
            if (count == 3)
                winner = true;
        }
        for (int i = 0; i < 3; i++)
        {
            count = 0;
            for (int j = 0; j < 3; j++)
            {
                if (arr[j][i] == a)
                    count++;
            }
            if (count == 3)
                winner = true;
        }
        count = 0;
        for (int i = 2, j = 0; i >= 0, j < 3; i--, j++)
        {
            if (arr[i][j] == a)
                count++;
        }
        if (count == 3)
            winner = true;
        count = 0;
        for (int i = 0, j = 0; i < 3, j < 3; i++, j++)
        {
            if (arr[i][j] == a)
                count++;
        }
        if (count == 3)
            winner = true;

        return winner;
    }
    int checkWin()
    {
        bool win1 = false, win2 = false;
        win1 = winner(1);
        if (win1)
            return 1;
        win2 = winner(2);
        if (win2)
            return 2;
        return 0;
    }

    bool DrawCheck()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] == 0)
                    return false;
            }
        }
        return true;
    }
    void Play()
    {
        int turn = 0;
        while (true)
        {
            if (DrawCheck())
            {
                cout << "\033[2J\033[1;1H";
                cout << "Game Drawn!";
                exit(0);
            }
            cout << "\033[2J\033[1;1H";
            display();
            int row, col;
            do
            {
                cout << "Player " << turn + 1 << " play your turn \nEnter row no : ";
                cin >> row;
                cout << "Enter col no : ";
                cin >> col;
            } while (row > 3 || row < 1 || col > 3 || col < 1);
            if (arr[row - 1][col - 1] != 0)
            {
                cout << "Box already occupied ";
                continue;
            }
            arr[row - 1][col - 1] = turn + 1;
            int win = checkWin();
            if (win == 1)
            {
                cout << "\033[2J\033[1;1H";
                cout << "Player " << turn + 1 << " won!";
                exit(0);
            }
            if (win == 2)
            {
                cout << "\033[2J\033[1;1H";
                cout << "Player " << turn + 1 << " won!";
                exit(0);
            }
            turn = !turn;
        }
    }
};
int main()
{
    TicTacToe game;
    game.Play();
}