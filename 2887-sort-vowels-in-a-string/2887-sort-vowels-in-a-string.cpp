class Solution {
public:
    bool isVowel(char& ch){
        if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
            return true;
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            return true;
        return false;
    }
    string sortVowels(string s) {
        string vowels = "";
        for(auto ch: s){
            if(isVowel(ch)){
                vowels.push_back(ch);
            }
        }
        sort(vowels.begin(),vowels.end());


        int i =0;
        int j= 0;
        while(i<s.length()){
            if(isVowel(s[i])){
                s[i] = vowels[j];
                j++;
            }
            i++;
        }
        return s;

    }
};