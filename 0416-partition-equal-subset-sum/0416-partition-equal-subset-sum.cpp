class Solution {
public:
    int dp[200][20001];
    bool solve(vector<int>& nums,int i,long sum,long halfSum){
        if(halfSum==sum)return true;
        if(i>=nums.size())return false;
        if(dp[i][sum]!=-1)return dp[i][sum];
        bool take = solve(nums,i+1,sum+nums[i],halfSum);
        bool nonTake = solve(nums,i+1,sum,halfSum);

        return dp[i][sum] = (take || nonTake);
    }
    bool canPartition(vector<int>& nums) {
        long sum = 0;
        for(auto ele: nums){
            sum+=ele;
        }
        memset(dp,-1,sizeof(dp));
        if((sum&1)==1)return false;

        if(solve(nums,0,0,sum/2))return true;

        return false;
    }
};