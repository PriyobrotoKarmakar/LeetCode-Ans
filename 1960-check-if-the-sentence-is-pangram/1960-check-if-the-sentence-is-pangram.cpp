class Solution {
public:
    bool checkIfPangram(string s) {
        vector<bool> freq(26,false);
        for(auto ch: s){
            freq[ch-'a'] = true;
        }

        for(char ch = 'a';ch<='z';ch++){
            if(freq[ch-'a'] == false)return false;
        }
        return true;
    }
};