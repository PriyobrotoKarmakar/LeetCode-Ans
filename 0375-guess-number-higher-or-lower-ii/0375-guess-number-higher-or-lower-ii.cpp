class Solution {
public:
    vector<vector<int>> dp;
    int solveUsingRec(int start, int end) {
        // base case
        if (start >= end)
            return 0;

        int& dpAns = dp[start][end];
        if (dpAns != -1)
            return dpAns;
        int ans = INT_MAX;
        for (int x = start; x <= end; x++) {
            int left = solveUsingRec(start, x - 1);
            int right = solveUsingRec(x + 1, end);
            ans = min(ans, x + max(right, left));
        }
        return dpAns = ans;
    }
    int solveUsingTab(int n) {
        dp.resize(n + 10, vector<int>(n + 10, 0));

        for (int l = n; l >= 1; l--) {
            for (int r = 1; r <= n; r++) {
                if (l >= r)
                    continue;

                dp[l][r] = INT_MAX;

                for (int x = l; x <= r; x++) {
                    int cost = x + max(dp[l][x - 1], dp[x + 1][r]);
                    dp[l][r] = min(dp[l][r], cost);
                }
            }
        }

        return dp[1][n];
    }
    int getMoneyAmount(int n) {

        int ans = 0;
        // dp.resize(n+1,vector<int>(n+1,-1));
        // ans = solveUsingMemo(1, n);
        ans = solveUsingTab(n);
        return ans;
    }
};