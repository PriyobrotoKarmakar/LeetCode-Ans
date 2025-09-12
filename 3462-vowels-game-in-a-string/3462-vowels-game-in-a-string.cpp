class Solution {
public:
    bool isVowel(const char& ch){
        if(ch=='a' or ch=='e' or ch=='i' or ch=='o' || ch=='u')return true;
        return false;
    }
    bool doesAliceWin(string s) {
        for(const char& ch:s){
            if(isVowel(ch))return true;
        }
        return false;
    }
};