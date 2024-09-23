class Solution {
public:
    int solve(int i,string& s, unordered_set<string>& st,int& n,unordered_map<int,int>&dp){
        //base case
        if(i>=n)return 0;
        if(dp.count(i))return dp[i];
        //not take the curr char
        int result  = 1+solve(i+1,s,st,n,dp);

        //take the curr char
        for(int j=i;j<n;j++){
            string curr = s.substr(i,j-i+1);
            if(st.count(curr)){
                result = min(result,solve(j+1,s,st,n,dp));
            }
        }

        return dp[i]=result;
    }
    int minExtraChar(string s, vector<string>& dict) {
        unordered_set<string>st(dict.begin(),dict.end());
        unordered_map<int,int>dp;
        int i=0;
        int n = s.size();
        return solve(i,s,st,n,dp);
    }
};