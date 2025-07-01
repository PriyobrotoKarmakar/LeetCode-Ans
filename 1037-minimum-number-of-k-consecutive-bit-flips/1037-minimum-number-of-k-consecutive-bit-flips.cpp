class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> q;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // Remove flips that are out of the window
            if (!q.empty() && q.front() <= i - k) {
                q.pop();
            }

            // If current bit needs flipping
            if (q.size() % 2 == nums[i]) {
                if (i + k > n) return -1;
                q.push(i);
                ans++;
            }
        }

        return ans;
    }
};
