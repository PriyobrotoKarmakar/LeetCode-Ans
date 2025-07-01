class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left = 0, right = 0;
        deque<int> incQ; // increasing deque
        deque<int> decQ; // decreasing deque
        int maxLen = 0;

        for (; right < nums.size(); right++) {
            int ele = nums[right];

            // Fill decreasing deque
            while (!decQ.empty() && ele > decQ.back()) {
                decQ.pop_back();
            }
            decQ.push_back(ele);

            // Fill increasing deque
            while (!incQ.empty() && ele < incQ.back()) {
                incQ.pop_back();
            }
            incQ.push_back(ele);

            // Check limit condition
            while (decQ.front() - incQ.front() > limit) {
                if (decQ.front() == nums[left]) {
                    decQ.pop_front();
                }
                if (incQ.front() == nums[left]) {
                    incQ.pop_front();
                }
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
