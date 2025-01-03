class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0;
        for (auto ele : nums) {
            totalSum += ele;
        }
        long long  ans = 0;
        long long firstSum = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            int ele = nums[i];
            firstSum += ele;
            
            if (firstSum >= (totalSum-firstSum))
                ans++;
        }
        return ans;
    }
};