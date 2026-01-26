class Solution {
public:
    vector<vector<int>> dp;
    int solveUsingRec(vector<int>& arr, map<pair<int, int>, int>& maxi, int s,
                      int e) {
        // base case
        if (s >= e)
            return 0;

        int& dpAns = dp[s][e];
        if (dpAns != -1)
            return dpAns;
        int ans = INT_MAX;
        for (int k = s; k < e; k++) {
            int leftRecAns = solveUsingRec(arr, maxi, s, k);
            int rightRecAns = solveUsingRec(arr, maxi, k + 1, e);
            int currAns = maxi[{s, k}] * maxi[{k + 1, e}];
            ans = min(ans, currAns + leftRecAns + rightRecAns);
        }

        return dpAns = ans;
    }
    int solveUsingTab(vector<int>& arr, map<pair<int, int>, int>& maxi, int n) {
        dp.resize(n + 1, vector<int>(n + 1, 0));

        for (int s = n - 1; s >= 0; s--) {
            for (int e = 0; e <= n - 1; e++) {
                if (s >= e)
                    continue;

                int& dpAns = dp[s][e];
                int ans = INT_MAX;
                for (int k = s; k < e; k++) {
                    int leftDpAns = dp[s][k];
                    int rightDpAns = dp[k + 1][e];
                    int currAns = maxi[{s, k}] * maxi[{k + 1, e}];
                    ans = min(ans, currAns + leftDpAns + rightDpAns);
                }
                dpAns = ans;
            }
        }
        return dp[0][n - 1];
    }
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    maxi[{i, j}] = arr[j];
                } else {
                    maxi[{i, j}] = max(maxi[{i, j - 1}], arr[j]);
                }
            }
        }
        // dp.resize(n + 1, vector<int>(n + 1, -1));
        int s = 0;
        int e = n - 1;
        int ans = solveUsingTab(arr, maxi, n);
        return ans;
    }
};