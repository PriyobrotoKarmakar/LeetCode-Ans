class Solution {
public:
    vector<vector<int>> dp;
    bool isSafe(vector<int>& curr, vector<int>& prev) {
        if ((curr[0] <= prev[0]) && (curr[1] <= prev[1]) &&
            (curr[2] <= prev[2]))
            return true;
        else
            return false;
    }
    int solveUsingRec(vector<vector<int>>& cuboids, int curr, int prev) {
        // base case
        if (curr >= cuboids.size())
            return 0;
        int& ans = dp[curr][prev + 1];
        if (ans != -1)
            return ans;
        int incl = 0;
        if (prev == -1 || isSafe(cuboids[prev], cuboids[curr])) {
            incl = cuboids[curr][2] + solveUsingRec(cuboids, curr + 1, curr);
        }

        int excl = 0 + solveUsingRec(cuboids, curr + 1, prev);

        return ans = max(incl, excl);
    }

    int solveUsingTab(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        dp.resize(n + 1, vector<int>(n + 1, 0));

        // curr ->[n-1 -> 0]
        // prev -> [curr-1->-1]

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int incl = 0;
                if (prev == -1 || isSafe(cuboids[prev], cuboids[curr])) {
                    incl = cuboids[curr][2] + dp[curr + 1][curr+1];
                }

                int excl = 0 + dp[curr + 1][prev+1];
                dp[curr][prev+1] = max(incl, excl);
            }
        }
        return dp[0][-1+1];
    }
    int maxHeight(vector<vector<int>> cuboids) {
        int n = cuboids.size();
        // dp.resize(n + 1, vector<int>(n + 1, -1));
        for (auto& cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        sort(cuboids.begin(), cuboids.end());

        int curr = 0;
        int prev = -1;
        // return solveUsingRec(cuboids, curr, prev);
        return solveUsingTab(cuboids);
    }
};