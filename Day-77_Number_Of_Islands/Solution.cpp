//DFS Recursive
class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};

    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != '1') return;

        grid[i][j] = '0';  // mark as visited

        for (int k = 0; k < 4; ++k) {
            dfs(grid, i + dir[k], j + dir[k + 1]);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '1') {
                    ++count;
                    dfs(grid, i, j);
                }

        return count;
    }
};
//DFS Recursive Using Visited Array
class Solution {
public:
    int count=0;
    vector<int> dir{0,1,0,-1,0};
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    count++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
    void dfs(int row,int col,vector<vector<char>> &grid,vector<vector<int>> &visited){
        if( row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col]=='0' || visited[row][col]){
            return;
        }
        visited[row][col]=true;
        for(int i=0;i<4;i++){
            dfs(row+dir[i],col+dir[i+1],grid,visited);
        }
    }
};

//DFS Iterative
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        vector<pair<int, int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '1') {
                    count++;
                    stack<pair<int, int>> stk;
                    stk.push({i, j});
                    while (!stk.empty()) {
                        auto [x, y] = stk.top(); stk.pop();
                        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] != '1') continue;
                        grid[x][y] = '0';
                        for (auto& [dx, dy] : directions)
                            stk.push({x + dx, y + dy});
                    }
                }

        return count;
    }
};
//BFS Using Queue
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '1') {
                    ++count;
                    q.push({i, j});
                    grid[i][j] = '0';
                    while (!q.empty()) {
                        auto [x, y] = q.front(); q.pop();
                        for (auto& [dx, dy] : directions) {
                            int nx = x + dx, ny = y + dy;
                            if (nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == '1') {
                                grid[nx][ny] = '0';
                                q.push({nx, ny});
                            }
                        }
                    }
                }

        return count;
    }
};

//Union-Find Disjoint Set
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> parent(m * n, -1);

        auto find = [&](int x) {
            while (x != parent[x])
                x = parent[x] = parent[parent[x]];
            return x;
        };

        auto unite = [&](int x, int y) {
            int fx = find(x), fy = find(y);
            if (fx != fy) parent[fx] = fy;
        };

        int count = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    int id = i * n + j;
                    parent[id] = id;
                    count++;
                }
            }

        vector<pair<int, int>> dirs = {{0,1},{1,0}};
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    for (auto [dx, dy] : dirs) {
                        int ni = i + dx, nj = j + dy;
                        if (ni < m && nj < n && grid[ni][nj] == '1') {
                            int id1 = i * n + j;
                            int id2 = ni * n + nj;
                            if (find(id1) != find(id2)) {
                                unite(id1, id2);
                                count--;
                            }
                        }
                    }
                }
            }

        return count;
    }
};
