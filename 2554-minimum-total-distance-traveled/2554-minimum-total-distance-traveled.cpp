class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();
        
        // Sort robots and factories by position to align them
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        // dp[i][j] represents the minimum distance to repair the first i robots using the first j factories
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));
        dp[0][0] = 0; // No robots, no distance

        for (int j = 1; j <= m; ++j) { // Iterate over each factory
            dp[0][j] = 0; // No robots assigned to this factory, distance is zero
            for (int i = 1; i <= n; ++i) { // Iterate over each robot
                long long totalDistance = 0;
                // Assign k robots to the j-th factory within its limit
                for (int k = 1; k <= min(i, factory[j - 1][1]); ++k) {
                    totalDistance += abs(robot[i - k] - factory[j - 1][0]);
                    if (dp[i - k][j - 1] != LLONG_MAX) { // Check to avoid overflow
                        dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + totalDistance);
                    }
                }
                // Also consider the option of not using this factory
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            }
        }
        // The answer is the minimum distance to repair all robots using all factories
        return dp[n][m];
    }
};