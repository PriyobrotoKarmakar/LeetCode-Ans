class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string word = "";
        int i = 0;
        int j = 0;
        while(j<s.size()){
            if(j-i+1 == k){
                word.push_back(s[j]);
                ans.push_back(word);
                i = j+1;
                j = i;
                word = "";
            }else{
                word.push_back(s[j]);
                j++;
            }
        }
        if(word.length()==0)return ans;
        if(word.length()<k){
            while(word.length()<k){
                word.push_back(fill);
            }
            ans.push_back(word);
        }
        return ans;

    }
};