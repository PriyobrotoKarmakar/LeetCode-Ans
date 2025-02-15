class Solution {
public:
    bool check(int i, int currSum, string s, int num){
        if(i==s.length()){
            return currSum==num;
        }
        if(currSum>num){
            return false;
        }
        bool possible = false;
        for(int j = i;j<s.length();j++){
            string subStr = s.substr(i,j-i+1);
            int val = stoi(subStr);
            // possible = possible || check(j+1,currSum+val,s,num);
            if(check(j+1,currSum+val,s,num)){
                return true;
            }
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1;i<=n;i++){
            int sq = i*i;
            string st = to_string(sq);
            if(check(0, 0, st, i)){
                ans+=sq;
            }
        }
        return ans;
    }
};