class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums,
                                vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> cumulativeSum(n, 0);
        cumulativeSum[0] = 0;
        for (int i = 1; i < n; i++) {
            if ((nums[i] & 1) == (nums[i - 1] & 1)) {
                cumulativeSum[i] = cumulativeSum[i - 1] + 1;
            } else {
                cumulativeSum[i] = cumulativeSum[i - 1];
            }
        }
        vector<bool> ans;
        for (vector<int>& query : queries) {
            int start = query[0];
            int end = query[1];
            if (cumulativeSum[end] - cumulativeSum[start] == 0) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};