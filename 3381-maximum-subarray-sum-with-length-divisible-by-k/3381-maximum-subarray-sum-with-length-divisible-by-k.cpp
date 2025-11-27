class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        long long ans = LLONG_MIN;
        for (int start = 0; start < k; start++) {
            long long curr = 0;
            long long best = LLONG_MIN;

            for (int i = start; i + k - 1 < n; i += k) {
                int r = i + k - 1;  // must be valid full block
                long long blockSum = pref[r + 1] - pref[i];
                curr = max(blockSum, curr + blockSum);
                best = max(best, curr);
            }
            ans = max(ans, best);
        }
        return ans;
    }
};