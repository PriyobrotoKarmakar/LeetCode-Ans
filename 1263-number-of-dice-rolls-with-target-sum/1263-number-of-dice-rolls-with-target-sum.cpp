#define ll long long
#define MOD 1000000007

class Solution {
public:
    vector<vector<ll>> dp;
    int solve(int n, int k, int target) {
        if (n == 0) {
            if (target == 0)
                return 1;
            else
                return 0;
        }
        ll& DP = dp[n][target];
        if (DP != -1)
            return DP;
        ll ans = 0;
        for (int i = 1; i <= k; i++) {
            if (target >= i) {
                ans += solve(n - 1, k, target - i) ;
            }
        }

        return DP = ans% MOD;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n + 1, vector<ll>(target + 1, -1));
        return solve(n, k, target);
    }
};