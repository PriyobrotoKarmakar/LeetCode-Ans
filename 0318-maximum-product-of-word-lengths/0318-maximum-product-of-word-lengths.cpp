class Solution {
public:
    bool isNotCommon(string& a, string& b){
        int mask = 0;
        for(char ch: a){
            mask =  mask | (1<<(ch-'a'+1));
        }

        for(char ch: b){
            if(mask & (1<<(ch-'a'+ 1))){
                return false;
            }
        }
        return true;
    }
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(isNotCommon(words[i],words[j])){
                    int lengths = words[i].length() * words[j].length();
                    ans = max(ans,lengths);
                }
            }
        }
        return ans;
    }
};