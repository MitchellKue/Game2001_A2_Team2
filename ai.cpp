
/*
Group Members:
Raheem Kue Mitchell - 101605581
Jeya Hachey - 101456091

Course: GAME 2001
Project: Tic-Tac-Toe with AI
File: ai.cpp
Date: November 23, 2026

Description:
This file contains the implementation of the AI logic for the
Tic-Tac-Toe game. It uses the minimax algorithm to evaluate board
states and choose the best possible move for the computer player.
*/

#include "ai.h"
#include "board.h"

int minimax(char board[SIZE][SIZE], bool isMaximizing, char aiSymbol, char humanSymbol)
{
    // base cases
    if (checkWin(board, aiSymbol))
    {
        return 10;
    }

    if (checkWin(board, humanSymbol))
    {
        return -10;
    }

    if (checkDraw(board))
    {
        return 0;
    }

    if (isMaximizing)
    {
        int bestScore = -1000;

        // try every empty space for the ai
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = aiSymbol;
                    int score = minimax(board, false, aiSymbol, humanSymbol);
                    board[i][j] = ' ';

                    if (score > bestScore)
                    {
                        bestScore = score;
                    }
                }
            }
        }

        return bestScore;
    }
    else
    {
        int bestScore = 1000;

        // try every empty space for the human
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = humanSymbol;
                    int score = minimax(board, true, aiSymbol, humanSymbol);
                    board[i][j] = ' ';

                    if (score < bestScore)
                    {
                        bestScore = score;
                    }
                }
            }
        }

        return bestScore;
    }
}

void findBestMove(char board[SIZE][SIZE], char aiSymbol, char humanSymbol, int &bestRow, int &bestCol)
{
    int bestScore = -1000;
    bestRow = -1;
    bestCol = -1;

    // test every empty space and keep the move with the best score
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = aiSymbol;

                int score = minimax(board, false, aiSymbol, humanSymbol);

                board[i][j] = ' ';

                if (score > bestScore)
                {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
}