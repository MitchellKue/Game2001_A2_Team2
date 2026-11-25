/*
Group Members:
Raheem Kue Mitchell - 101605581
Jeya Hachey - 101456091

Course: GAME 2001
Project: Tic-Tac-Toe with AI
File: ai.h
Date: November 23, 2026

Description:
This header file contains the function prototypes for the AI component
of the Tic-Tac-Toe game.
*/


#ifndef AI_H
#define AI_H

#include "board.h"

// recursive minimax function
int minimax(char board[SIZE][SIZE], bool isMaximizing, char aiSymbol, char humanSymbol);

// finds the best move for the ai
void findBestMove(char board[SIZE][SIZE], char aiSymbol, char humanSymbol, int &bestRow, int &bestCol);

#endif