class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0], freq = 0;
        for (int x : nums) {
            if (freq == 0)
                ans = x;
            if (x == ans)
                freq++;
            else
                freq--;
        }
        return ans;
    }
};