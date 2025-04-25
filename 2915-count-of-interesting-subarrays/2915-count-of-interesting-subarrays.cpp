class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();                      // \U0001f4cf Get the size of the array
        unordered_map<int, int> cnt;              // \U0001f9ee Hash map to count prefix mod frequencies
        long long res = 0;                        // \U0001f9fe Result to count valid subarrays
        int prefix = 0;                           // ➕ Prefix sum that counts valid % occurrences
        cnt[0] = 1;                               // \U0001f7e2 Base case: 0 mod seen once

        for (int i = 0; i < n; i++) {
            prefix += nums[i] % modulo == k;      // \U0001f50d Increment prefix if nums[i] satisfies % condition
            res += cnt[(prefix - k + modulo) % modulo];  // \U0001f4c8 Add count of matching prefix mod
            cnt[prefix % modulo]++;               // \U0001f5c3️ Update the current prefix mod in map
        }

        return res;                               // ✅ Return result
    }
};