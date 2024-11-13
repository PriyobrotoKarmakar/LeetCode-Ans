class Solution {
public:
    int solve(vector<int>& nums,int lastIdx,int i,vector<vector<int>>&dp){
            if(i>=nums.size())return 0;
            int include = 0;

            if(dp[lastIdx+1][i]!=-1)return dp[lastIdx+1][i];


            if(lastIdx == -1 || nums[lastIdx]<nums[i]){
                 include = 1 + solve(nums,i,i+1,dp);
            }
            int exclude = 0 + solve(nums,lastIdx,i+1,dp);

            dp[lastIdx+1][i] = max(include,exclude);
            return dp[lastIdx+1][i];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(nums,-1,0,dp);
    }
};