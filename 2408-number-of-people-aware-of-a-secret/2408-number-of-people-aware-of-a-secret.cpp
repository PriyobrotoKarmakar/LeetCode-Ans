class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> dp;
    int solve(int day, int delay, int forget) {
        if (day == 1)
            return 1;
        if(dp[day]!=-1)return dp[day];
        int total = 0;
        for (int d = day - forget + 1; d <= day - delay; d++) {
            if (d > 0)
                total = (total + solve(d, delay, forget)) % MOD;
        }

        return dp[day] = total;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int ans = 0;
        dp.resize(n+1,-1);
        for (int day = n - forget + 1; day <= n; day++) {
            if (day > 0) {
                ans = (ans + solve(day, delay, forget)) % MOD;
            }
        }

        return ans;
    }
};