class Solution {
public:
    void longestPalindromicSubstring(vector<int>& lps, string check) {
        int i=0;
        int j=1;
        while(j<check.length()){
            if(check[i]==check[j]){
                i++;
                lps[j]=i;
                j++;
            }else{
                if(i==0){
                    j++;
                }else{
                    i = lps[i-1];
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string check = s + '#' + rev;
        vector<int>lps(check.length(),0);
        longestPalindromicSubstring(lps, check);
        int i=lps[lps.size()-1];
        string remainingString = s.substr(i);
        reverse(remainingString.begin(),remainingString.end());
        return remainingString+s; 
    }
};