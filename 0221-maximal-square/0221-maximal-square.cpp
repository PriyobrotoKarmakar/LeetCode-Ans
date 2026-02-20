class Solution {
public:
    int ans = 0;
    vector<vector<int>> dp;
    int solve(vector<vector<char>>& arr, int i, int j, int m, int n) {
        if (i >= n || j >= m)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (arr[i][j] == '0') {

            return dp[i][j] = 0;
        }

        int right = solve(arr, i, j + 1, m, n);
        int down = solve(arr, i + 1, j, m, n);
        int rightDown = solve(arr, i + 1, j + 1, m, n);
        dp[i][j] = 1+min({right,down,rightDown});
        ans = max(ans,dp[i][j]);
        return dp[i][j];
    }
    int maximalSquare(vector<vector<char>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        dp.resize(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                solve(arr, i, j, m, n);
            }
        }
        return ans * ans;
    }
};