class Solution {
public:
    // int solve(vector<int>& nums, int i, vector<int>& dp) {
    //     if (i == 0)
    //         return nums[i];
    //     if (i < 0)
    //         return 0;
    //     if (dp[i] != -1)
    //         return dp[i];
    //     int inc = nums[i] + solve(nums, i - 2, dp);
    //     int exc = 0 + solve(nums, i - 1, dp);

    //     return dp[i] = max(inc, exc);
    // }
    int solveUsingBottomUP(vector<int>& nums, int n) {
        vector<int> dp(n + 1, -1);
        if(n==1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for (int i = 2; i < n; i++) {
            int inc = nums[i] + dp[i - 2];
            int exc = 0 + dp[i - 1];
            dp[i] = max(inc, exc);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n + 1, -1);
        // int i = 0;
        // int money = 0;
        // return solve(nums, n - 1, dp);
        return solveUsingBottomUP(nums,n);
    }
};