//Naive Backtracking Approach

bool isSafe(vector<string>& board, int row, int col, int n) {
    // Check vertical up
    for (int i = 0; i < row; ++i)
        if (board[i][col] == 'Q') return false;

    // Check diagonal up-left
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 'Q') return false;

    // Check diagonal up-right
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
        if (board[i][j] == 'Q') return false;

    return true;
}

void solve(int row, vector<string>& board, vector<vector<string>>& solutions, int n) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(row + 1, board, solutions, n);
            board[row][col] = '.'; // backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solve(0, board, solutions, n);
    return solutions;
}

//BackTracking Alternative Approach
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    // Check vertical up
    for (int i = 0; i < row; ++i)
        if (board[i][col] == 'Q') return false;

    // Check diagonal up-left
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 'Q') return false;

    // Check diagonal up-right
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
        if (board[i][j] == 'Q') return false;

    return true;
}

void solve(int row, vector<string>& board, vector<vector<string>>& solutions, int n) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(row + 1, board, solutions, n);
            board[row][col] = '.'; // backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solve(0, board, solutions, n);
    return solutions;
}

int main() {
    int n = 8;
    auto solutions = solveNQueens(n);
    cout << "Total Solutions: " << solutions.size() << "\n";
    for (auto& sol : solutions) {
        for (auto& row : sol)
            cout << row << "\n";
        cout << "\n";
    }
}

//Optimized Backtracking (Using Hash Arrays)
void solve(int row, int n, vector<string>& board,
           vector<int>& cols, vector<int>& diag1, vector<int>& diag2,
           vector<vector<string>>& solutions) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (cols[col] || diag1[row + col] || diag2[row - col + n - 1])
            continue;

        board[row][col] = 'Q';
        cols[col] = diag1[row + col] = diag2[row - col + n - 1] = 1;

        solve(row + 1, n, board, cols, diag1, diag2, solutions);

        board[row][col] = '.';
        cols[col] = diag1[row + col] = diag2[row - col + n - 1] = 0;
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    vector<int> cols(n, 0), diag1(2 * n - 1, 0), diag2(2 * n - 1, 0);
    solve(0, n, board, cols, diag1, diag2, solutions);
    return solutions;
}

//Bit Manipulation Approach
void solve(int n, int row, int cols, int diag1, int diag2, vector<int>& positions, vector<vector<int>>& solutions) {
    if (row == n) {
        solutions.push_back(positions);
        return;
    }

    int available = ((1 << n) - 1) & ~(cols | diag1 | diag2);
    while (available) {
        int bit = available & -available;
        int col = __builtin_ctz(bit); // count trailing zeros

        positions.push_back(col);
        solve(n, row + 1, cols | bit, (diag1 | bit) << 1, (diag2 | bit) >> 1, positions, solutions);
        positions.pop_back();

        available -= bit;
    }
}

vector<vector<int>> solveNQueensBitmask(int n) {
    vector<vector<int>> solutions;
    vector<int> positions;
    solve(n, 0, 0, 0, 0, positions, solutions);
    return solutions;
}




