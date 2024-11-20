#include <iostream>
#include "functions.h"

int main() {
    displayHeading();

    char board[SIZE][SIZE];  // The game board
    char currentPlayer = 'X';  // Player 1 starts as 'X'
    int row, col;

    initializeBoard(board);  // Initialize the board

    while (true) {
        printBoard(board);  // Display the current board

        // Ask the current player for their move (1-based indexing for user)
        std::cout << "Player " << currentPlayer << ", enter row (1-3) and column (1-3): ";
        std::cin >> row >> col;

        // Adjust input to 0-based indexing for the board
        row -= 1;  // Convert to 0-based index
        col -= 1;  // Convert to 0-based index

        // Make the move and check if it's valid
        if (makeMove(board, row, col, currentPlayer)) {
            // Check if the current player has won
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                break;
            }

            // Check if it's a draw
            if (checkDraw(board)) {
                printBoard(board);
                std::cout << "It's a draw!" << std::endl;
                break;
            }

            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            std::cout << "Invalid move, try again!" << std::endl;
        }
    }

    return 0;

};