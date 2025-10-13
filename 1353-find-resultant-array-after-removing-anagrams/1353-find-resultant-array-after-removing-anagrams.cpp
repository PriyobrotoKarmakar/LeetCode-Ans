class Solution {
public:
    bool isAnagram(string& s1, string& s2) {
        vector<int> letters(26);
        for (char ch : s1) {
            letters[ch - 'a']++;
        }
        for (char ch : s2) {
            letters[ch - 'a']--;
        }
        for (int letter : letters) {
            if (letter != 0)
                return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        for (int i = 1; i < words.size(); i++) {
            string s1 = ans.back();
            string s2 = words[i];

            if (!isAnagram(s1, s2)) {
                ans.push_back(s2);
            }
        }
        return ans;
    }
};