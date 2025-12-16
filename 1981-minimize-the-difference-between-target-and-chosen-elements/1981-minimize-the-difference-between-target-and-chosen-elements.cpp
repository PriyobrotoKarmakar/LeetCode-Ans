class Solution {
public:
    vector<vector<int>> dp; 

    int solve(vector<vector<int>>& mat, int i, int sum, int target) {
        
        if (i == mat.size()) {
            return abs(sum - target);
        }

        
        if (dp[i][sum] != -1) return dp[i][sum];

        int ans = INT_MAX;
        
        for (int ele : mat[i]) {
            ans = min(ans, solve(mat, i + 1, sum + ele, target));
        }

        return dp[i][sum] = ans;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size();
       
        dp.assign(n + 1, vector<int>(target + 10000, -1));
        return solve(mat, 0, 0, target);
    }

};