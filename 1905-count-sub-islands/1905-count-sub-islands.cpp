class Solution {
public:
    int n, m;
    bool isWater(int i, int j, vector<vector<int>>& grid2) {
        return (i < 0 || i >= n || j < 0 || j >= m || grid2[i][j] != 1);
    }
    bool isIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i,
                  int j) {
        if (isWater(i, j, grid2))
            return true;

        grid2[i][j] = INT_MIN;

        bool up = isIsland(grid1, grid2, i - 1, j);
        bool down = isIsland(grid1, grid2, i + 1, j);
        bool left = isIsland(grid1, grid2, i, j - 1);
        bool right = isIsland(grid1, grid2, i, j + 1);

        return grid1[i][j] == 1 & up & down & left & right;
    }
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        n = grid2.size();
        m = grid2[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && isIsland(grid1, grid2, i, j)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};