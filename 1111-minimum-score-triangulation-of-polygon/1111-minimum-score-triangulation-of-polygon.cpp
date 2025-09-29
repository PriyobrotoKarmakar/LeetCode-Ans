class Solution {
public:
    int solve(vector<int>& values, int i, int j, vector<vector<int>>& dp) {
        //{1,2,3,4,5,6,7}
        // i j
        if (j - i + 1 < 3)
            return 0;
        int ans = INT_MAX;
        int& dpAns = dp[i][j];
        if (dpAns != -1)
            return dpAns;
        for (int k = i + 1; k < j; k++) {
            int recAns = (values[i] * values[k] * values[j]) +
                         solve(values, i, k, dp) + solve(values, k, j, dp);
            ans = min(recAns, ans);
        }
        return dpAns = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(values, 0, n - 1, dp);
    }
};