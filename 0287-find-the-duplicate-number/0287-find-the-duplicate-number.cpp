class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int idx = 0;
        while (true) {
            if (nums[idx] < 0)
                return idx;

            nums[idx] *= -1;
            idx = abs(nums[idx]);
        }
        return -1;
    }
};