class Solution {
public:
    bool isValid(int nx, int ny, int n, int m, vector<vector<bool>>& visited,vector<vector<char>>& grid) {

        if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] &&
            grid[nx][ny] == '1')
            return true;
        else
            return false;
    }
    void BFS(int i, int j, vector<vector<char>>& grid,
             vector<vector<bool>>& visited) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> dir{
            {0, -1}, // left
            {0, 1},  // right
            {1, 0},  // up
            {-1, 0}  // down
        };

        visited[i][j] = true;

        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dir) {
                int nx = dx + x, ny = dy + y;
                if (isValid(nx, ny, n, m, visited,grid)) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int island = 0;

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