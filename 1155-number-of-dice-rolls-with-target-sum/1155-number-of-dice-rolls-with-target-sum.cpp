#define MOD 1000000007
class Solution {
public:
    vector<vector<long long>> dp;
    long long int solveUsingRec(int n, int k, int target) {
        // base
        if(n==0 && target==0)return 1;
        if(n==0 || target<0)return 0;
        // solve
        long long int& dpAns = dp[n][target];
        if (dpAns != -1)
            return dpAns;
        long long int ways = 0;
        for (int face = 1; face <= k; face++) {
            ways = (ways + solveUsingRec(n - 1, k, target - face)) % MOD;
        }
        return dpAns = ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n + 1, vector<long long int>(target + 1, -1));
        int ans = solveUsingRec(n, k, target) % MOD;
        return ans;
    }
};