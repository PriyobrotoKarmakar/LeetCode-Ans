class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<int> rowCheck(row, 0);
        vector<int> colCheck(col, 0);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    rowCheck[i]++;
                    colCheck[j]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 &&
                    (rowCheck[i] > 1 or colCheck[j] > 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};