#ifndef BOARD_H
#define BOARD_H

const int SIZE = 3;

// sets every spot on the board to a blank space
void initializeBoard(char board[SIZE][SIZE]);

// prints the board to the screen
void displayBoard(char board[SIZE][SIZE]);

// checks if a move is inside the board and the chosen spot is empty
bool isValidMove(char board[SIZE][SIZE], int row, int col);

// places X or O on the board
void makeMove(char board[SIZE][SIZE], int row, int col, char symbol);

// checks if the given symbol has won
bool checkWin(char board[SIZE][SIZE], char symbol);

// checks if the board is full
bool checkDraw(char board[SIZE][SIZE]);

#endif