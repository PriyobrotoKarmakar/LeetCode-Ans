class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int markIndex = -1;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                markIndex = i - 1;
                break;
            }
        }

        if (markIndex != -1) {

            for (int i = n - 1; i > markIndex; i--) {
                if (nums[i] > nums[markIndex]){
                    swap(nums[markIndex], nums[i]);
                    break;
                    }
            }
        }
        reverse(nums.begin() + markIndex + 1, nums.end());
    }
};