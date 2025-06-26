class Solution {
public:
    int longestSubsequence(string s, int k) {
     long long ans = 0;
     long long twoPower = 1;
     int n = s.length();
     for(int i = n-1;i>=0;i--){
        if(s[i]=='0')
            ans++;
        else if(twoPower<=k){
            k-=twoPower;
            ans++;
        }
        if(twoPower<=k)twoPower<<=1;
     }   
     return ans;
    }
};