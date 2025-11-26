#define ll long long
#define MOD 1000000007
class Solution {
public:
    int n, m, div;
    ll dfs(vector<vector<int>>& arr, int i, int j, int rem,
           vector<vector<vector<ll>>>& dp) {

        if (i >= n || j >= m)
            return 0;

        rem = (rem + arr[i][j]) % div;

        if (i == n - 1 && j == m - 1)
            return rem == 0 ? 1 : 0;

        if (dp[i][j][rem] != -1)
            return dp[i][j][rem];

        ll right = dfs(arr, i, j + 1, rem, dp);
        ll down = dfs(arr, i + 1, j, rem, dp);

        return dp[i][j][rem] = (right + down) % MOD;
    }

    int numberOfPaths(vector<vector<int>>& arr, int k) {
        div = k;
        n = arr.size();
        m = arr[0].size();
        vector<vector<vector<ll>>> dp(
            n, vector<vector<ll>>(m, vector<ll>(k + 1, -1)));
        return dfs(arr, 0, 0, 0, dp);
    }
};
