class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        
        int maximumDiff = 0;
        for(int i = 0;i<nums.size()-1;i++){
            maximumDiff = max(maximumDiff,abs(nums[i+1]-nums[i]));
            maximumDiff = max(maximumDiff, abs(nums[nums.size() - 1] - nums[0]));
        }
        return maximumDiff;
    }
};