class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string>ans;
        map<string,int> freq;
        istringstream st1(s1),st2(s2);
        string word;
        while(st1>>word){
            freq[word]++;
        }
        while(st2>>word){
            freq[word]++;
        }

        for(const pair<const string,int>& pair: freq){
            if(pair.second==1){
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};