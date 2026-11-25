/*
Group Members:
Raheem Kue Mitchell - 101605581
Jeya Hachey - 101456091

Course: GAME 2001
Project: Tic-Tac-Toe with AI
File: game.cpp
Date: November 23, 2026

Description:
This file contains the implementation of the main game logic for the
Tic-Tac-Toe program. Manages turn order, player interaction, and game progression.
*/


#include <iostream>
#include <limits>
#include <cctype>
#include <string>
#include "game.h"
#include "board.h"
#include "ai.h"

using namespace std;

// simple helper function for safely reading integer input
int getNumberInput()
{
    int value;

	// Loop until valid input is received from the user
    while (true)
    {
        cin >> value;

        if (cin.fail())
        {
            // user entered something that was not a number
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
        }
        else
        {
            return value;
        }
    }
}

// helper function for choosing X or O
char getSymbolChoice()
{
    char symbol;

    while (true)
    {
        cin >> symbol;
        symbol = toupper(symbol);

		// check if the input is valid (either 'X' or 'O')
        if (symbol == 'X' || symbol == 'O')
        {
            return symbol;
        }

		// if the input is invalid, prompt the user again
        cout << "Invalid choice. Please enter X or O: ";
    }
}

void playTwoPlayerGame()
{
    char board[SIZE][SIZE];
    initializeBoard(board);

    string player1Name;
    string player2Name;
    char player1Symbol;
    char player2Symbol;

    cout << "\n--- Two Player Mode ---\n";

    cout << "Enter Player 1 name: ";
    cin >> player1Name;

    cout << "Enter Player 2 name: ";
    cin >> player2Name;

    cout << player1Name << ", choose X or O: ";
    player1Symbol = getSymbolChoice();

    // assign the other symbol to player 2
    if (player1Symbol == 'X')
    {
        player2Symbol = 'O';
    }
    else
    {
        player2Symbol = 'X';
    }

    string currentName;
    char currentSymbol;

    // X always goes first
    if (player1Symbol == 'X')
    {
        currentName = player1Name;
        currentSymbol = player1Symbol;
    }
    else
    {
        currentName = player2Name;
        currentSymbol = player2Symbol;
    }

    while (true)
    {
        int row, col;

		// display the current state of the board
        displayBoard(board);

        cout << currentName << "'s turn (" << currentSymbol << ")" << endl;
        cout << "Enter row (1-3): ";
        row = getNumberInput();

        cout << "Enter column (1-3): ";
        col = getNumberInput();

        // convert from user input 1-3 into array indexes 0-2
        row--;
        col--;

        if (!isValidMove(board, row, col))
        {
            cout << "That move is not valid. Try again.\n";
            continue;
        }

		// make the move on the board
        makeMove(board, row, col, currentSymbol);

        if (checkWin(board, currentSymbol))
        {
            displayBoard(board);
            cout << currentName << " wins!\n";
            break;
        }

        if (checkDraw(board))
        {
            displayBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        // switch turns
        if (currentName == player1Name)
        {
            currentName = player2Name;
            currentSymbol = player2Symbol;
        }
        else
        {
            currentName = player1Name;
            currentSymbol = player1Symbol;
        }
    }
}

void playOnePlayerGame()
{
    char board[SIZE][SIZE];
    initializeBoard(board);

    string playerName;
    char playerSymbol;
    char aiSymbol;
    char currentSymbol;

    cout << "\n--- One Player Mode ---\n";

    cout << "Enter your name: ";
    cin >> playerName;

    cout << "Choose X or O: ";
    playerSymbol = getSymbolChoice();

    // computer gets the other symbol
    if (playerSymbol == 'X')
    {
        aiSymbol = 'O';
    }
    else
    {
        aiSymbol = 'X';
    }

    // X always goes first
    if (playerSymbol == 'X')
    {
        currentSymbol = playerSymbol;
    }
    else
    {
        currentSymbol = aiSymbol;
    }

    while (true)
    {
        displayBoard(board);

        if (currentSymbol == playerSymbol)
        {
            int row, col;

            cout << playerName << "'s turn (" << playerSymbol << ")" << endl;
            cout << "Enter row (1-3): ";
            row = getNumberInput();

            cout << "Enter column (1-3): ";
            col = getNumberInput();

            row--;
            col--;

            if (!isValidMove(board, row, col))
            {
                cout << "That move is not valid. Try again.\n";
                continue;
            }

            makeMove(board, row, col, playerSymbol);

            if (checkWin(board, playerSymbol))
            {
                displayBoard(board);
                cout << playerName << " wins!\n";
                break;
            }
        }
        else
        {
            int bestRow, bestCol;

            cout << "Computer's turn (" << aiSymbol << ")" << endl;

            findBestMove(board, aiSymbol, playerSymbol, bestRow, bestCol);
            makeMove(board, bestRow, bestCol, aiSymbol);

            if (checkWin(board, aiSymbol))
            {
                displayBoard(board);
                cout << "Computer wins!\n";
                break;
            }
        }

        if (checkDraw(board))
        {
            displayBoard(board);
            cout << "It's a draw!\n";
            break;
        }

        // switch turns
        if (currentSymbol == playerSymbol)
        {
            currentSymbol = aiSymbol;
        }
        else
        {
            currentSymbol = playerSymbol;
        }
    }
}