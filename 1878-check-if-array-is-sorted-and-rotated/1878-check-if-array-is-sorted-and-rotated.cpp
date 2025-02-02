class Solution {
public:
    bool solve(vector<int>& nums, vector<int>& sorted, int k) {
        for (int i = 0; i < sorted.size(); i++) {
            if (sorted[i] != nums[(i + k) % sorted.size()])
                
            return false;
        }
        return true;
    }
    bool check(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        if (nums == sorted)
            return true;
        for (int i = 1; i < nums.size(); i++) {
            if (solve(nums, sorted, i)) {
                return true;
            }
        }

        return false;
    }
};