#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check if there's a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    // Check upper diagonal on right side
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int row, int N) {
    if (row >= N) {
        return true; // All queens are placed
    }
    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1; // Place the queen
            if (solveNQueensUtil(board, row + 1, N)) {
                return true;
            }
            board[row][col] = 0; // If placing queen doesn't lead to a solution, backtrack
        }
    }
    return false; // If queen can't be placed in any column in this row, return false
}

void solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0)); // Initialize the board
    if (solveNQueensUtil(board, 0, N)) {
        // Print the solution
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Solution does not exist." << endl;
    }
}

int main() {
    int N;
    cout << "Enter the number of queens (N): ";
    cin >> N;
    solveNQueens(N);
    return 0;
}
