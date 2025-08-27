class Solution {
public:
    int n, m;
    int dir[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int solve(int i, int j, int d, bool canTurn, int val,
              vector<vector<int>>& grid) {
        int delI = i + dir[d][0];
        int delJ = j + dir[d][1];

        // not valid
        if (delI < 0 || delJ < 0 || delI >= n || delJ >= m ||
            grid[delI][delJ] != val) {
            return 0;
        }
        int result = 0;
        int newVal = val == 2 ? 0 : 2;
        // include
        int include = 1 + solve(delI, delJ, d, canTurn, newVal, grid);
        result = max(result, include);
        // exclude
        if (canTurn) {
            int exclude =
                1 + solve(delI, delJ, (d + 1) % 4, !canTurn, newVal, grid);
            result = max(result, exclude);
        }

        return result;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    // start point
                    for (int d = 0; d <= 3; d++) {
                        ans = max(ans, 1 + solve(i, j, d, true, 2, grid));
                    }
                }
            }
        }

        return ans;
    }
};