class Solution {
public:
    bool check(string substr, unordered_map<char, int>& freqS1, string& s1) {
        unordered_map<char, int> freqS2;
        for (auto ch : substr) {
            freqS2[ch]++;
        }
        for (auto ch : s1) {
            if (freqS1[ch] != freqS2[ch]) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s1.length())
            return false;
        unordered_map<char, int> freqS1;
        for (auto ch : s1) {
            freqS1[ch]++;
        }
        int sizeOfTheWindow = s1.length();
        int i = 0;
        
        while (i + sizeOfTheWindow <= s2.length()) {
            string substr = s2.substr(i, sizeOfTheWindow);
            if (check(substr, freqS1, s1))
                return true;
            i++;
            
        }
        return false;
    }
};