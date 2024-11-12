class Solution {
public:
    int solve(vector<int>& nums,int index,vector<int>&dp){
        if(index>=nums.size())
            return 0;


        if(dp[index]!=-1)
            return dp[index];

        int include = nums[index] + solve(nums,index+2,dp);
        int exclude = 0 + solve(nums,index+1,dp);

        
        dp[index] = max(include,exclude);
        return dp[index];   
    }
    int solveTobulation(vector<int>& nums){
        int n = nums.size();
        int next1 = 0;
        int next2 = 0;
        for(int i=n-1;i>=0;i--){
            int include = nums[i] + next2;
            int exclude = 0 + next1;
            int curr = max(include,exclude);

            next2 = next1;
            next1 = curr;
        }
        return next1;
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        int index = 0;
        // return solve(nums,index,dp);
        return solveTobulation(nums);
    }
};