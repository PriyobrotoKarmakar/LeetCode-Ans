class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> increasingLength(n, 1);
        
        // Precompute the length of increasing sequences starting at each index
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                increasingLength[i] = increasingLength[i + 1] + 1;
            }
        }
        
        int low = 1, high = n / 2, maxK = 0;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canFindAdjacentIncreasingSubarrays(increasingLength, mid)) {
                maxK = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return maxK;
    }

private:
    bool canFindAdjacentIncreasingSubarrays(const vector<int>& increasingLength, int k) {
        int n = increasingLength.size();
        for (int i = 0; i <= n - 2 * k; ++i) {
            if (increasingLength[i] >= k && increasingLength[i + k] >= k) {
                return true;
            }
        }
        return false;
    }
};
