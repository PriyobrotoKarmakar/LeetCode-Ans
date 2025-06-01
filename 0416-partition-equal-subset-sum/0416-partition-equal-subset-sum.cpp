class Solution {
public:
    int half;
    bool solve(vector<int>&nums,int i,int target){
        if(target==half)return true;
        if(target>half || i>=nums.size()){
            return false;
        }

        bool inc = solve(nums,i+1,target+nums[i]);
        bool exc = solve(nums,i+1,target);

        return inc | exc;
        
    }
    bool solveMem(vector<int>&nums,int i,int target,vector<vector<int>>&dp){
        if(target==half)return true;
        if(target>half || i>=nums.size()){
            return false;
        }
        if(dp[i][target]!=-1)return dp[i][target];


        bool inc = solveMem(nums,i+1,target+nums[i],dp);
        bool exc = solveMem(nums,i+1,target,dp);

        return dp[i][target] = (inc | exc);
        
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if((sum&1)==1)return false;
        vector<vector<int>>dp(nums.size(),vector<int>(sum,-1));
        half = sum>>1;
        // return solve(nums,0,0);
        return solveMem(nums,0,0,dp);
    }
};