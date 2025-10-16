class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        vector<int> freq(value, 0);

        // Step 1: Count frequency of each remainder class
        for (auto &num : nums) {
            int r = (num % value + value) % value;
            freq[r]++;
        }

        // Step 2: Find the smallest MEX
        int mex = 0;
        while (freq[mex % value] > 0) {
            freq[mex % value]--;
            mex++;
        }

        return mex;
    }
};
// Please Upvote 