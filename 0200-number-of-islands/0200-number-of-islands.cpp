class Solution {
private:
    void BFS(int i, int j, vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;

        
        vector<pair<int, int>> direction{
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}, // Up, Down, Left, Right
        };

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto [dx, dy] : direction) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && 
                    !visited[nx][ny] && grid[nx][ny] == '1') {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int island = 0;

       
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
            
                if (!visited[i][j] && grid[i][j] == '1') {
                    BFS(i, j, grid, visited);
                    island++;
                }
            }
        }
        return island;
    }
};
