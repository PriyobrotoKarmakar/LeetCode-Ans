class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int sum = 0;
        int ans = INT_MAX;
        while(j<n){
            sum += nums[j];
            while(sum >= target){
                ans = min((j-i+1),ans);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};