/*
Group Members:
Raheem Kue Mitchell - 101605581
Jeya Hachey - 101456091

Course: GAME 2001
Project: Tic-Tac-Toe with AI
File: main.cpp
Date: November 23, 2026

Description:
This file contains the main function for the Tic-Tac-Toe program.
It starts the program, displays the menu, and runs the game logic based on the user's selected mode.
*/

#include <iostream>
#include <limits>
#include "game.h"

using namespace std;

int main()
{
    int choice;

    cout << "Welcome to Tic-Tac-Toe\n";
    cout << "1. Two Player Game\n";
    cout << "2. One Player Game vs AI\n";
    cout << "Enter your choice: ";

	// Loop until valid input is received from the user
    while (true)
    {
		// Get user input for game mode
        cin >> choice;

		// Validate user input
        if (cin.fail() || (choice != 1 && choice != 2))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter 1 or 2: ";
        }
        else
        {
			// Valid input received, exit the loop
            break;
        }
    }

	// Start the game based on the user's choice
    if (choice == 1)
    {
        playTwoPlayerGame();
    }
    else
    {
        playOnePlayerGame();
    }

	// TODO: add play again functionality
    // 
	// End of the program
    return 0;
}