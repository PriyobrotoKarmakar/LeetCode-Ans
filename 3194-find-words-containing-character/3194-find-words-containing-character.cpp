class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        
        vector<int> ans;

        for(int i = 0;i<words.size();i++){
            string word = words[i];
            if(word.find(x)!=string::npos){
                ans.push_back(i);
            }
        }
        return ans;

    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();