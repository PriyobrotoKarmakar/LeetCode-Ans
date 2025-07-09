class Solution {
public:
        int m ;
        int n ;
        vector<vector<int>> dp; 
    int solveUsingTab(string& text1, string& text2){
        
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        
        return dp[0][0];
    }
    int solveUsingRec(string& text1, string& text2,int i,int j){
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = 0;
        if(text1[i]==text2[j]){
            ans = 1 + solveUsingRec(text1,text2,i-1,j-1);
        }else{
            ans = max(solveUsingRec(text1,text2,i,j-1),solveUsingRec(text1,text2,i-1,j));
        }
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
         m = text1.length();
         n = text2.length();
         dp.resize(m + 1, vector<int>(n + 1, -1));
        return solveUsingRec(text1,text2,m-1,n-1);
    }
};
