class Solution {
public:
    string st;
    int n;
    vector<vector<int>> dp;

    int solveUsingRec(int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        if (st[i] == st[j]) {
            dp[i][j] = 2 + solveUsingRec(i + 1, j - 1);
        } else {
            dp[i][j] = max(solveUsingRec(i + 1, j), solveUsingRec(i, j - 1));
        }

        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        st = s;
        n = s.length();
        dp.resize(n, vector<int>(n, -1));
        return solveUsingRec(0, n - 1);
    }
};
