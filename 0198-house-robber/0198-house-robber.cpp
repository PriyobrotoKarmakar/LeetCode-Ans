class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int i = 0) {
        if (i >= nums.size())
            return 0;
        int& ans = dp[i];
        if (ans != -1)
            return ans;
        int include = nums[i] + solve(nums, dp, i + 2);
        int exclude = solve(nums, dp, i + 1);

        return ans = max(include, exclude);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return solve(nums, dp);
    }
};