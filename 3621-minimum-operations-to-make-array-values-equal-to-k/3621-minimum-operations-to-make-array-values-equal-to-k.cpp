class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> distinctValues(nums.begin(), nums.end());
    int opCount = 0;

    for (int value : distinctValues) {
        if (value > k) {
            opCount++;
        } else if (value < k) {
            return -1;
        }
    }

    return opCount;
    }
};