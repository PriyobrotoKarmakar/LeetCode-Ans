#define ll long long
class Solution {
public:
    int superSum = 0;
    ll solve(vector<int>& arr, int target, int idx, ll sum,
             map<array<ll, 2>, ll>& dp) {
        if (idx >= arr.size())
            return sum == target ? 1 : 0;

        if (dp.count({idx, sum}))
            return dp[{idx, sum}];
        ll subtract = solve(arr, target, idx + 1, sum - arr[idx], dp);
        ll add = solve(arr, target, idx + 1, sum + arr[idx], dp);

        return dp[{idx, sum}] = subtract + add;
    }
    int solveUsingVectorDP(vector<int>& arr, int target, int idx, ll sum,
                           vector<vector<int>>& dp) {
        if (idx >= arr.size())
            return sum == target ? 1 : 0;

        if (dp[idx][superSum + sum]!=-1)
            return dp[idx][superSum + sum];
        ll subtract = solveUsingVectorDP(arr, target, idx + 1, sum - arr[idx], dp);
        ll add = solveUsingVectorDP(arr, target, idx + 1, sum + arr[idx], dp);

        return dp[idx][superSum + sum] = subtract + add;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        superSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>>dp(n,vector<int>(2*superSum + 1,-1));
        // map<array<ll, 2>, ll> dp;
        // return solve(nums, target, 0, 0LL, dp);
        return solveUsingVectorDP(nums,target,0,0,dp);
    }
};
