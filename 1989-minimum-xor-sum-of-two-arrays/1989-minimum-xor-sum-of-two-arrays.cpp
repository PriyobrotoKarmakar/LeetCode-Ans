class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<long long> dp((1 << n), INT_MAX);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
            int alreadySet = __builtin_popcount(mask);
            for (int j = 0; j < n; j++) {
                if ((mask & (1 << j)) == 0) {
                    dp[mask | (1 << j)] =
                        min(dp[mask | (1 << j)],
                            dp[mask] + (nums1[alreadySet] ^ nums2[j]));
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};