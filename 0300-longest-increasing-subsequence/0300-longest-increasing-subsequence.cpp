class Solution {
public:
    vector<vector<int>> dp;
    int solveUsingRec(vector<int>& nums, int index, int prevIndex) {
        // base
        if (index >= nums.size())
            return 0;
        // logic
        int include = 0;
        int curr = nums[index];
        if (prevIndex == -1 || curr > nums[prevIndex]) {
            include = 1 + solveUsingRec(nums, index + 1, index);
        }
        int exclude = solveUsingRec(nums, index + 1, prevIndex);

        return max(include, exclude);
    }
    int solveUsingMemo(vector<int>& nums, int index, int prevIndex) {
        // base
        if (index >= nums.size())
            return 0;
        // logic
        int& dpAns = dp[index][prevIndex+1];
        if(dpAns!=-1)return dpAns;
        int include = 0;
        int curr = nums[index];
        if (prevIndex == -1 || curr > nums[prevIndex]) {
            include = 1 + solveUsingMemo(nums, index + 1, index);
        }
        int exclude = solveUsingMemo(nums, index + 1, prevIndex);

        return dpAns = max(include, exclude);
    }
    int solveUsingTab(vector<int>& nums,int n){
        dp.resize(n+1,vector<int>(n+2,0));

        

        for(int index = n-1;index>=0;index--){
            for(int prevIndex = index ;prevIndex>=-1;prevIndex--){
                int include = 0;
                int curr = nums[index];
                if (prevIndex == -1 || curr > nums[prevIndex]) {
                    include = 1 + dp[index + 1][index+1];
                }
                int exclude = dp[index + 1][prevIndex+1];

                dp[index][prevIndex+1] = max(include, exclude);
            }
        }

        return dp[0][0];

    }

    int lengthOfLIS(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        int prevIndex = -1;
        // dp.resize(n,vector<int>(n+1,-1));
        // int ans = solveUsingMemo(nums, index, prevIndex);
        int ans = solveUsingTab(nums,n);
        return ans;
    }
};