class Solution {
public:
    int solve(vector<int>coins,int amount,vector<int>&dp){
        if(amount==0){
            return 0;
        }
        int mincoin = INT_MAX;
        if(dp[amount]!=-1)return dp[amount];
        for(int coin: coins){
            if(coin<=amount){
                int recans = solve(coins,amount-coin,dp);
                if(recans!=INT_MAX){
                    mincoin = min(mincoin,recans+1);
                }
            }
        }
        dp[amount] = mincoin;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans = solve(coins,amount,dp);
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};