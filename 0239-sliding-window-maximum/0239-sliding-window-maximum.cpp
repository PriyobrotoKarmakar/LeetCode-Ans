class Solution {
public:
    multiset<int> ms;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq; // Stores indices
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // 1. Remove index out of current window (from front)
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // 2. Remove smaller elements from the back (Maintain Decreasing
            // Order) If current num > back num, the back num is useless.
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // 3. Add current index
            dq.push_back(i);

            // 4. Record result (front is always the max)
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};