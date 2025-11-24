class Solution {
public:
    bool solve(vector<int>& nums, int div, int thres) {
        int sum = 0;
        for (auto ele : nums) {
            sum += ceil((double)ele / (double)div);
        }
        return sum <= thres;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        int ans = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (solve(nums, mid, threshold)) {
                end = mid - 1;
                ans = mid;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};