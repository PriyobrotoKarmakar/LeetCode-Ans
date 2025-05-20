class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> decrementTracker(n + 1, 0);

        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            decrementTracker[left]++;
            if (right + 1 < n) {
                decrementTracker[right + 1]--;
            }
        }

        int currentDecrement = 0;
        for (int i = 0; i < n; i++) {
            currentDecrement += decrementTracker[i];
            if (nums[i] > currentDecrement) {
                return false;
            }
        }

        return true;
    }
};