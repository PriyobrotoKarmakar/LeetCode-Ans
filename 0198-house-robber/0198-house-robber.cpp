class Solution {
public:
    int solve( vector<int>& nums,int i,vector<int>&dp){
        if(i==0)return nums[i];
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int inc = nums[i] + solve(nums,i-2,dp);
        int exc = 0 + solve(nums,i-1,dp);

        return dp[i] = max(inc,exc);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        int i = 0;
        int money = 0;
        return solve(nums,n-1,dp);
    }
};