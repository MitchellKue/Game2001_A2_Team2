#include <iostream>
#include "board.h"

using namespace std;

void initializeBoard(char board[SIZE][SIZE])
{
    // fill the whole board with blank spaces
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[SIZE][SIZE])
{
    cout << endl;
    cout << "   1   2   3" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << i + 1 << " ";

        for (int j = 0; j < SIZE; j++)
        {
            cout << " " << board[i][j] << " ";

            if (j < SIZE - 1)
            {
                cout << "|";
            }
        }

        cout << endl;

        if (i < SIZE - 1)
        {
            cout << "  ---+---+---" << endl;
        }
    }

    cout << endl;
}

bool isValidMove(char board[SIZE][SIZE], int row, int col)
{
    // make sure row and col are inside the board
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE)
    {
        return false;
    }

    // make sure the spot is empty
    if (board[row][col] != ' ')
    {
        return false;
    }

    return true;
}

void makeMove(char board[SIZE][SIZE], int row, int col, char symbol)
{
    board[row][col] = symbol;
}

bool checkWin(char board[SIZE][SIZE], char symbol)
{
    // check rows
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
        {
            return true;
        }
    }

    // check columns
    for (int j = 0; j < SIZE; j++)
    {
        if (board[0][j] == symbol && board[1][j] == symbol && board[2][j] == symbol)
        {
            return true;
        }
    }

    // check main diagonal
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
    {
        return true;
    }

    // check other diagonal
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol)
    {
        return true;
    }

    return false;
}

bool checkDraw(char board[SIZE][SIZE])
{
    // if there is even one empty space, it is not a draw yet
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }

    return true;
}