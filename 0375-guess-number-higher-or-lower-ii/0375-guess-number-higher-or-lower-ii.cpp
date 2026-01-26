class Solution {
public:
    vector<vector<int>> dp;
    int solve(int start, int end) {
        // base case
        if (start >= end)
            return 0;
        
        int& dpAns = dp[start][end];
        if(dpAns!=-1)return dpAns;
        int ans = INT_MAX;
        for (int x = start; x <= end; x++) {
            int left = solve(start, x - 1);
            int right = solve(x + 1, end);
            ans = min(ans, x + max(right, left));
        }
        return dpAns = ans;
    }
    int getMoneyAmount(int n) {

        int ans = 0;
        dp.resize(n+1,vector<int>(n+1,-1));
        ans = solve(1, n);
        return ans;
    }
};