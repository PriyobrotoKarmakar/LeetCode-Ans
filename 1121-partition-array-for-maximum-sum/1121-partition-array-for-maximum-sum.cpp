class Solution {
public:
    int n;
    int solve(vector<int>& arr, int k, int i, vector<int>& dp) {

        if (i == n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int maxi = 0, ans = 0;
        for (int j = 1; j <= k; j++) {
            if (i + j - 1 < n) {
                maxi = max(maxi, arr[i + j - 1]);
                ans = max(ans, maxi * j + solve(arr, k, i + j, dp));
            }
        }

        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        vector<int> dp(n + 1, -1);
        return solve(arr, k, 0, dp);
    }
};
