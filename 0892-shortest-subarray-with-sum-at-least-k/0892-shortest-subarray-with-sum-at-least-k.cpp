class Solution {
public:
    int shortestSubarray(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> cimulativeSum(n, 0);
        deque<int> dq;
        int j = 0;
        int ans = INT_MAX;
        while (j < n) {
            if (j == 0) {
                cimulativeSum[j] = nums[j];
            } else {
                cimulativeSum[j] = cimulativeSum[j - 1] + nums[j];
            }

            if (cimulativeSum[j] >= target) {
                ans = min(ans, j + 1);
            }

            while (!dq.empty() && (cimulativeSum[j] - cimulativeSum[dq.front()]) >= target) {
                ans = min(ans,j - dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && cimulativeSum[j] <= cimulativeSum[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(j);
            j++;
        }
        return ans==INT_MAX ? -1 : ans;
    }
};