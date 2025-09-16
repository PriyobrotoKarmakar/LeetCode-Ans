class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& arr, int i, int target) {
        if (target == 0) return 0;
        if (i >= arr.size()) return INT_MAX;

        int& ans = dp[i][target];
        if (ans != -1) return ans;

        int take = INT_MAX;
        if (target - arr[i] >= 0) {
            int sub = solve(arr, i, target - arr[i]);
            if (sub != INT_MAX) take = 1 + sub;  
        }

        int nontake = solve(arr, i + 1, target);

        return ans = min(take, nontake);
    }

    int numSquares(int n) {
        vector<int> perfectSq;
        for (int i = 1; i * i <= n; i++) {
            perfectSq.push_back(i * i);
        }
        dp.resize(perfectSq.size() + 1, vector<int>(n + 1, -1));
        int res = solve(perfectSq, 0, n);
        return res == INT_MAX ? -1 : res;
    }
};
