class Solution {
    final int MOD = 10;
    public int[] Comb(int n){
        int nhf = n/2;
        int[] dp = new int[nhf+1];
        dp[0] = 1;               
        for(int i=1;i<=n;i++){
            for(int j=Math.min(nhf,i);j>=1;j--){
                dp[j] = (dp[j]+dp[j-1])%MOD;
            }
        }
        return dp;
    }

    public int triangularSum(int[] nums) {
        int ans = 0;
        int n = nums.length;
        int comb[] = Comb(n-1);
        for(int i=0;i<n;i++){  //Comb gen8 till half , after that repeats itself
            ans = (ans + (nums[i]*comb[i>(n-1)/2 ? n-1-i:i])%MOD)%MOD;
        } 
        return ans;
    }
}