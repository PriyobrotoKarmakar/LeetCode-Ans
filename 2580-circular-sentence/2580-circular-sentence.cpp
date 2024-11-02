class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        string word;
        vector<string>words;
        while(ss>>word){
            words.push_back(word);
        }

        for(int i=0;i<words.size();i++){
            string curr  = words[i];
            string next = words[(i+1)%words.size()];
            if(curr[curr.length()-1]!=next[0])return false;
        }
        return true;
    }
};