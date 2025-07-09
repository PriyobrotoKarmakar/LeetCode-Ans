class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        // return solve(n - 1, m - 1, word1, word2, dp);
        return solveUsingTab(word1, word2);
    }
    int solveUsingTab(string& word1, string& word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = i;
        for (int j = 0; j <= m; j++)
            dp[0][j] = j;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int del = 1 + dp[i - 1][j];
                    int ins = 1 + dp[i][j - 1];
                    int rep = 1 + dp[i - 1][j - 1];
                    dp[i][j] = min({del, ins, rep});
                }
            }
        }

        return dp[n][m];
    }

    int solve(int i, int j, string& word1, string& word2,
              vector<vector<int>>& dp) {
        if (j < 0)
            return i + 1;
        if (i < 0)
            return j + 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j]) {
            dp[i][j] = solve(i - 1, j - 1, word1, word2, dp);
        } else {
            int del = 1 + solve(i - 1, j, word1, word2, dp);
            int ins = 1 + solve(i, j - 1, word1, word2, dp);
            int rep = 1 + solve(i - 1, j - 1, word1, word2, dp);
            dp[i][j] = min({del, ins, rep});
        }

        return dp[i][j];
    }
};
