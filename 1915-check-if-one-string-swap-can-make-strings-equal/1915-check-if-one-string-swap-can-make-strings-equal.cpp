class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)return true;
        int mismatch = 0;
        unordered_map<char,int>freq1;
        unordered_map<char,int>freq2;
        for(char ch:s1){
            freq1[ch]++;
        }
        for(char ch:s2){
            freq2[ch]++;
        }
        for(int i = 0;i<s1.length();i++){
            if(freq1[s2[i]]!=freq2[s2[i]])return false;

            if(s1[i]!=s2[i])
                mismatch++;
        }
        return mismatch==2;
    }
};