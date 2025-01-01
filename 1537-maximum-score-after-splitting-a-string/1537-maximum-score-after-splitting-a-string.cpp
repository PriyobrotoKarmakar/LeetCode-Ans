class Solution {
public:
    int numberOfZeros(string s){
        int count = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0')count++;
        }
        return count;
    }
    int numberOfOnes(string s){
        int count = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')count++;
        }
        return count;
    }

    int maxScore(string s) {
        int ans = 0;
        for(int i=1;i<s.length();i++){
            int j = s.length()-i;
            string zero = s.substr(0,i);
            string one = s.substr(i,j);
            ans = max(ans,(numberOfZeros(zero)+numberOfOnes(one)));
        }
        return ans;
    }
};