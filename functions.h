#include <string>

// Function declarations
void displayHeading();


#define SIZE 3  // Defining the size of the board (3x3)

// Function to initialize the board with empty spaces
void initializeBoard(char board[SIZE][SIZE]);

// Function to print the board
void printBoard(char board[SIZE][SIZE]);

// Function to check if the current player has won
bool checkWin(char board[SIZE][SIZE], char player);

// Function to check if the board is full (i.e., a draw)
bool checkDraw(char board[SIZE][SIZE]);

// Function to make a move
bool makeMove(char board[SIZE][SIZE], int row, int col, char player);



