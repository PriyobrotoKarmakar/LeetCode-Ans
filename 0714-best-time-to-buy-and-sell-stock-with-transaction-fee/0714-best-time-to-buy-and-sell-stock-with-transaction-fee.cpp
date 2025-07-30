class Solution {
public:
    int f(int i, int buy, vector<int>& prices, int fee, vector<vector<int>>& dp) {
        if (i == prices.size()) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];

        int profit = 0;
        if (buy) {
            // Buy or skip
            int take = -prices[i] + f(i + 1, 0, prices, fee, dp);
            int notTake = f(i + 1, 1, prices, fee, dp);
            profit = max(take, notTake);
        } else {
            // Sell or skip
            int sell = prices[i] - fee + f(i + 1, 1, prices, fee, dp);
            int notSell = f(i + 1, 0, prices, fee, dp);
            profit = max(sell, notSell);
        }

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, prices, fee, dp);  // Start from index 0, allowed to buy
    }
};
