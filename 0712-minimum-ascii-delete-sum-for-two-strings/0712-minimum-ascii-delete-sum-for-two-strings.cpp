class Solution {
public:
    int n, m;
    vector<vector<int>> dp; int solve(string& s1, string& s2, int i, int j) {
        if (i >= n && j >= m)
            return 0;

        if (i >= n) {
            int sum = 0;
            for (int k = j; k < m; k++)
                sum += s2[k];
            return sum;
        }

        if (j >= m) {
            int sum = 0;
            for (int k = i; k < n; k++)
                sum += s1[k];
            return sum;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j]) {
            dp[i][j] = solve(s1, s2, i + 1, j + 1);
        } else {
            int deleteFromS1 = s1[i] + solve(s1, s2, i + 1, j);
            int deleteFromS2 = s2[j] + solve(s1, s2, i, j + 1);
            dp[i][j] = min(deleteFromS1, deleteFromS2);
        }

        return dp[i][j];
    }

    int minimumDeleteSum(string s1, string s2) {
        n = s1.length();
        m = s2.length();
        dp.resize(n + 1, vector<int>(m + 1, -1));
        return solve(s1, s2, 0, 0);
    }
};