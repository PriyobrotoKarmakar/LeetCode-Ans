class Solution {
public:
    vector<vector<int>> dp;
    bool isSafe(vector<int>& bottom, vector<int>& top) {
        return ((bottom[0] >= top[0]) && (bottom[1] >= top[1]) &&
                (bottom[2] >= top[2]));
    }
    int solveUsingRec(vector<vector<int>>& cuboids, int curr, int prev) {
        // base case
        if (curr >= cuboids.size())
            return 0;

        // memo
        int& ans = dp[curr][prev + 1];
        if (ans != -1)
            return ans;

        // logic
        int include = 0;
        if (prev == -1 || isSafe(cuboids[prev], cuboids[curr])) {
            include = cuboids[curr][2] + solveUsingRec(cuboids, curr + 1, curr);
        }
        int exclude = solveUsingRec(cuboids, curr + 1, prev);
        return ans = max(include, exclude);
    }
    int solveUsingTab(vector<vector<int>>& cuboids, int n) {
        dp.resize(n + 1, vector<int>(n + 1, 0));

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {

                int include = 0;
                if (prev == -1 || isSafe(cuboids[prev], cuboids[curr])) {
                    include = cuboids[curr][2] + dp[curr + 1][curr + 1];
                }

                int exclude = dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for (vector<int>& cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.rbegin(), cuboids.rend());
        int n = cuboids.size();
        // dp.resize(n + 1, vector<int>(n + 1, -1));
        int curr = 0;
        int prev = -1;
        int ans = solveUsingTab(cuboids, n);
        return ans;
    }
};