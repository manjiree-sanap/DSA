// Write a recursive program to find the solution of placing n queens on a chess board so that no queen takes each other (backtracking).
#include <iostream>
#include <vector>

using namespace std;

// Function to check if a queen can be placed on the board
bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(vector<vector<int>>& board, int row, int n) {
    if (row == n) {
        return true; // All queens are placed
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1; // Place the queen

            if (solveNQueens(board, row + 1, n)) {
                return true;
            }

            board[row][col] = 0; // Backtrack
        }
    }

    return false; // No valid placement found
}

// Function to print the chessboard
void printBoard(const vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] ? "1 " : "0 ");
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQueens(board, 0, n)) {
        cout << "One possible solution:\n";
        printBoard(board, n);
    } else {
        cout << "No solution exists for " << n << " queens." << endl;
    }

    return 0;
}
