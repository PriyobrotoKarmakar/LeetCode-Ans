class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> same;   // For "gg", "aa", etc.
        unordered_map<string, int> pairs;  // For "ab", "cd", etc.
        int ans = 0;
        bool hasCenter = false;

        for (const string& word : words) {
            if (word[0] == word[1]) {
                same[word]++;
            } else {
                pairs[word]++;
            }
        }

        // Case 1: Mirror pairs like "ab" and "ba"
        for (auto& [word, count] : pairs) {
            string reversed = word;
            swap(reversed[0], reversed[1]);

            if (pairs.find(reversed) != pairs.end()) {
                int mirrorCount = min(count, pairs[reversed]);
                ans += mirrorCount * 4;
                pairs[reversed] = 0; // avoid double-counting
                pairs[word] = 0;
            }
        }

        // Case 2 & 3: Same-letter words like "gg"
        for (auto& [word, count] : same) {
            ans += (count / 2) * 4;
            if (count % 2 == 1) {
                hasCenter = true;
            }
        }

        // Case 3: One "gg" can go in center
        if (hasCenter) ans += 2;

        return ans;
    }
};
