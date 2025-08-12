class Solution {
public:

    int mod = 1e9+7;
    int func(vector<int> &arr , int n , int i , int sum , vector<vector<int>> &dp ){
        if(sum == n ) return 1;
        if(i == arr.size() || sum > n){
            return 0;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        int take = func(arr , n , i+1 ,sum + arr[i] , dp ); 
        int notake = func(arr , n , i+1 ,sum , dp);
        
        return dp[i][sum] =  (take + notake) % mod;
    }

    int numberOfWays(int n, int x) {
        vector<int> arr;
        for(int i = 1 ; n >= pow(i , x);i++){
            arr.push_back( (int)pow(i , x));
        }
        vector<vector<int>> dp(arr.size()+1 , vector<int>(n+1 , 0));

        // return func(arr , n , 0 , 0 , dp );

        for(int i = 0 ;i <= arr.size();i++) dp[i][n] = 1;

        for(int i = arr.size()-1;i>=0;i--){

            for(int sum = 0 ; sum < n;sum++){
                int take = 0;
                if(sum +  arr[i] <= n) take = dp[i+1][sum+arr[i]];
                int notake = dp[i+1][sum];
                dp[i][sum] = (take + notake)%mod;
            }
        }

        return dp[0][0];

    }
};