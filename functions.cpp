#include <stdio.h>
#include "functions.h"

#include <iostream>

void displayHeading(){
  std::cout << "Lets play Tic Tac Toe \n";
   std::cout << R"(
  _______ _        _______           _______         
 |__   __(_)      |__   __|         |__   __|        
    | |   _  ___     | | __ _  ___     | | ___   ___ 
    | |  | |/ __|    | |/ _` |/ __|    | |/ _ \ / _ \
    | |  | | (__     | | (_| | (__     | | (_) |  __/
    |_|  |_|\___|    |_|\__,_|\___|    |_|\___/ \___|
    )" << std::endl;
};

// Function to initialize the board with empty spaces
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';  // Empty space
        }
    }
}

// Function to print the board
void printBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cout << board[i][j];
            if (j < SIZE - 1) std::cout << " | ";  // Print separator
        }
        std::cout << std::endl;
        if (i < SIZE - 1) {
            std::cout << "---------" << std::endl;  // Horizontal separator
        }
    }
}

// Function to check if the current player has won
bool checkWin(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||  // Row check
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {  // Column check
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||  // Diagonal check (top-left to bottom-right)
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {  // Diagonal check (top-right to bottom-left)
        return true;
    }
    return false;
}

// Function to check if the board is full (i.e., a draw)
bool checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {  // There's still an empty space
                return false;
            }
        }
    }
    return true;  // No empty spaces left
}

// Function to make a move
bool makeMove(char board[SIZE][SIZE], int row, int col, char player) {
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;  // Invalid move if the spot is already taken or out of bounds
}




