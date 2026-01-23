class Solution {
public:
    bool solve(vector<int>& nums, int i, vector<int>& dp) {
        int n = nums.size();
        if (i == n - 1)
            return true;
        if (i >= n)
            return false;

        if (dp[i] != -1)
            return dp[i];

        int maxJump = nums[i];
        for (int j = 1; j <= maxJump; j++) {
            if (solve(nums, i + j, dp)) {
                return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        bool ans = solve(nums, 0, dp);
        return ans;
    }
};