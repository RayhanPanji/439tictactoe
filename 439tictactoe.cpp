#include <iostream>
using namespace std;

const int SIZE = 3;

// Function prototypes
void initializeBoard(char board[SIZE][SIZE]);
void printBoard(const char board[SIZE][SIZE]);
bool makeMove(char board[SIZE][SIZE], int row, int col, char currentPlayer);
bool checkWinner(const char board[SIZE][SIZE], char currentPlayer);
bool isBoardFull(const char board[SIZE][SIZE]);

int main() {
    char board[SIZE][SIZE];
    char currentPlayer = 'X';
    int row, col;

    initializeBoard(board);

    do {
        // Print the current board
        printBoard(board);

        // Get the move from the current player
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        // Make the move
        if (makeMove(board, row, col, currentPlayer)) {
            // Check if the current player wins
            if (checkWinner(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            // Check if the board is full (draw)
            if (isBoardFull(board)) {
                printBoard(board);
                cout << "It's a draw!\n";
                break;
            }

            // Switch to the next player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Try again.\n";
        }
    } while (true);

    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(const char board[SIZE][SIZE]) {
    cout << "-------------\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|\n-------------\n";
    }
}

bool makeMove(char board[SIZE][SIZE], int row, int col, char currentPlayer) {
    if (board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return true;
    }
    return false;
}

bool checkWinner(const char board[SIZE][SIZE], char currentPlayer) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return true;
    }

    return false;
}

bool isBoardFull(const char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') {
                return false; // There is an empty cell
            }
        }
    }
    return true; // Board is full
}
