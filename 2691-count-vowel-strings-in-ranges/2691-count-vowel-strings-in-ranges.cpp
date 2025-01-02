class Solution {
public:
    vector<char> vowel{'a', 'e', 'i', 'o', 'u'};
    bool valid(string words) {
        bool c1 = false, c2 = false;
        for (auto ch : vowel) {
            if (words[0] == ch) {
                c1 = true;
            }
            if (words[words.length() - 1] == ch) {
                c2 = true;
            }
        }
        return c1 && c2;
    }
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
                                int n = words.size();
        vector<int> cummilativeSum(n, 0);
        for (int i = 0; i < n; i++) {
            string word = words[i];
            if (valid(word)) {
                cummilativeSum[i] = i > 0 ? (cummilativeSum[i - 1] + 1) : 1;
            } else {
                cummilativeSum[i] = i > 0 ? cummilativeSum[i - 1] : 0;
            }
        }
        vector<int>result;
        for(auto query: queries){
            int start = query[0];
            int end = query[1];
            result.push_back(cummilativeSum[end]-(start == 0 ? 0 : cummilativeSum[start - 1]));
        }
        return result;
    }
};