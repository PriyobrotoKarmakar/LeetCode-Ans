class Solution {
public:
    bool isValid(vector<int>& nums, int p, int mid) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] - nums[i] <= mid) {
                count++;
                i++;
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums.front(), res = INT_MAX;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isValid(nums, p, mid)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};