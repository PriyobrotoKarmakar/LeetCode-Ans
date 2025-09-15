class Solution {
public:
    bool check(string& word, unordered_map<char,bool>& brokenLettersHash){
        for(char ch: word){
            if(brokenLettersHash[ch]){
                return false;
            }
        }
        return true;
    }

    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,bool> brokenLettersHash;
        for(auto ch: brokenLetters){
            brokenLettersHash[ch] = true;
        }   
        stringstream ss(text);
        string word = "";
        int count  = 0;
        while(ss>>word){
            if(check(word,brokenLettersHash)){
                count++;
            }
        }

        return count;
        
    }
};