class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        // if(words.size()==1) return words;
        for(int i = 0;i<words.size();i++){
            if(i==0 || groups[i]!=groups[i-1])
                ans.push_back(words[i]);
        }

        return ans;
    }
};