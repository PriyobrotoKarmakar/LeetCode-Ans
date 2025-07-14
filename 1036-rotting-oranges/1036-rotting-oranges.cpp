class Solution {
public:
    vector<pair<int, int>> dir{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> visited;
    int ans = 0;

    bool isValid(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
            grid[i][j] == 2 || grid[i][j] == 0 || visited[i][j] == true) {
            return false;
        }
        return true;
    }

        queue<pair<int, int>> q;
    void bfs(int i, int j, vector<vector<int>>& grid) {
        
        while (!q.empty()) { 
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [a, b] : dir) {
                    int nx = x + a;
                    int ny = y + b;
                    if (isValid(nx, ny, grid)) {
                        visited[nx][ny] = true; 
                        grid[nx][ny] = 2;       
                        q.push({nx, ny});
                    }
                }
            }
            ans++;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        visited.resize(n, vector<bool>(m)); 
        ans = -1;  

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2 && !visited[i][j]) {
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    bfs(i, j, grid);
                }
            }
        }

        for (int i = 0; i < n; i++) {   
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return max(ans, 0);
    }
};
