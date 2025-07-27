class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int i = 0;
        int j = i + 1;
        int n = nums.size();
        int ans = 0;
        while (j + 1 < n) {
            if ((nums[i] > nums[j] && nums[j] < nums[j + 1]) ||
                (nums[i] < nums[j] && nums[j] > nums[j + 1])) {
                ans++;
                i = j;
            }

            j++;
        }
        return ans;
    }
};