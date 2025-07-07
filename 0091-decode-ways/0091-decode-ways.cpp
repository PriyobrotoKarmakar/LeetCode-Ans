class Solution {
public:
    int solve(string& s, int i, vector<int>& dp) {
        if (i == s.length())
            return 1;
        if (s[i] == '0')
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int ways = solve(s, i + 1, dp);
        if (i + 1 < s.length()) {
            int validNum = stoi(s.substr(i, 2));
            if (validNum >= 10 && validNum <= 26) {
                ways += solve(s, i + 2, dp);
            }
        }
        dp[i] = ways;
        return dp[i];
    }

    int solveUsingTab(string& s) {
        int n = s.length();
        vector<int> dp(n + 1);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0')
                continue;
            int ways = dp[i + 1];
            if (i + 1 < s.length()) {
                int validNum = stoi(s.substr(i, 2));
                if (validNum >= 10 && validNum <= 26) {
                    ways += dp[i + 2];
                }
            }
            dp[i] = ways;
        }
        return dp[0];
    }
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1, -1);
        // return solve(s, 0, dp);
        return solveUsingTab(s);
    }
};