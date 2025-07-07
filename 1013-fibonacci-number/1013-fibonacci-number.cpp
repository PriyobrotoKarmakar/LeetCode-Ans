class Solution {
public:
    int DP(int n, vector<int>&dp){
        if(n==0 || n==1)return n;
        if(dp[n]!=-1)return dp[n];
        dp[n] = DP(n-1,dp)+DP(n-2,dp);
        return dp[n];
    }
    int DP_Bottom_UP(int n){
        vector<int>dp(n+2,-1);
        dp[0] = 0;
        
        dp[1] = 1;
        for(int i = 2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    int dp_space_optimisation(int n){
        int first = 0;
        if(n==0)return 0;
        if(n==1)return 1;
        int second = 1;
        for(int i = 2;i<=n;i++){
            int third = first + second; 
            first = second;
            second = third;
        }
        return second;
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return dp_space_optimisation(n);
    }
};