class Solution {
public:
    int solve(vector<string> Words, string target) {
        int check = -1;
        int count = 0;
        for (auto ele : Words) {
            count++;
            int index = ele.find(target);
            cout<<index<<" ";
            if (index==0) {
                check = count;
                return check;
            }
        }
        return check;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        vector<string> Words;
        while (ss >> word) {
            Words.push_back(word);
        }
        return solve(Words, searchWord);
    }
};