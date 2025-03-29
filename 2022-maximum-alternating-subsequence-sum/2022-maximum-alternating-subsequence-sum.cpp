class Solution {
public:
    typedef long long ll;
    ll dp[100001][2];

    ll solve(int i, vector<int>&nums, bool isPositive){
        if(i>=nums.size())return 0;
        if(dp[i][isPositive]!=-1)return dp[i][isPositive];
        ll nonTake = solve(i+1,nums,isPositive);
        ll val = nums[i];
        //taking element first check the positivity;
        val = isPositive ? val: -val;

        ll take = solve(i+1, nums, !isPositive) + val;

        return dp[i][isPositive]  =  max(take,nonTake); 
    }


    ll maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,nums,true);
    }
};