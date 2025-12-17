class Solution {
public:
    vector<int>dp;
    int solve(vector<int>& nums,int i =0){
        if(i==nums.size()-1){
            return 0;
        }
        if(i>=nums.size()){
            return INT_MAX;
        }
        if(dp[i]!=-1)return dp[i];
        int ans = INT_MAX;
        for(int j = 1;j<=nums[i];j++){
            int recAns=solve(nums,i+j);
            if(recAns!=INT_MAX){
                ans = min(ans,1+recAns);
            }
        }
        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        dp.assign(nums.size()+1,-1);
        return solve(nums);
    }
};