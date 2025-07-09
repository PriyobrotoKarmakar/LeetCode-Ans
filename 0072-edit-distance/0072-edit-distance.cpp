class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(n - 1, m - 1, word1, word2, dp);
    }

    int solve(int i, int j, string& word1, string& word2, vector<vector<int>>& dp) {
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
