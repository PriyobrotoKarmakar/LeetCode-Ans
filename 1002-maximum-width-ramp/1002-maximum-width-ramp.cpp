class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> stack;

        // Step 1: Build a decreasing stack based on the array's values
        for (int i = 0; i < n; ++i) {
            if (stack.empty() || nums[stack.back()] > nums[i]) {
                stack.push_back(i);
            }
        }

        int maxRamp = 0;

        // Step 2: Traverse from the right and check for the maximum ramp width
        for (int j = n - 1; j >= 0; --j) {
            while (!stack.empty() && nums[stack.back()] <= nums[j]) {
                maxRamp = max(maxRamp, j - stack.back());
                stack.pop_back(); // We can only use each index once
            }
        }

        return maxRamp;
    }
};
