class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;
        
        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {
                // Flip current and next two elements
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ops++;
            }
        }
        
        // Check if transformation is successful
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) return -1;
        }
        
        return ops;
    }
};
