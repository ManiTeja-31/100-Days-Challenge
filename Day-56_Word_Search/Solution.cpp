//BackTracking Approach - Using Visited Array
class Solution {
public:
    vector<int> dir{0, 1, 0, -1, 0};

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j, 0, board, word, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int row, int col, int index, vector<vector<char>> &board, string &word, vector<vector<int>> &visited) {
        if (index == word.length()) return true;

        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() ||
            visited[row][col] || board[row][col] != word[index]) {
            return false;
        }

        visited[row][col] = true;
        for (int i = 0; i < 4; ++i) {
            int newRow = row + dir[i];
            int newCol = col + dir[i + 1];
            if (dfs(newRow, newCol, index + 1, board, word, visited)) {
                return true;
            }
        }
        visited[row][col] = false;  // backtrack
        return false;
    }
};
