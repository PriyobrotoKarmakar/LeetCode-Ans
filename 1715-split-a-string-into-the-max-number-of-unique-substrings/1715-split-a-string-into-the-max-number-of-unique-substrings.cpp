class Solution {
public:
    int backtrack(const string& s, int start, unordered_set<string>& seen) {
        if (start == s.size()) {
            return 0;
        }

        int maxSplits = 0;

        for (int i = start; i < s.size(); ++i) {
            string current = s.substr(start, i - start + 1);

            if (seen.find(current) == seen.end()) {
                seen.insert(current);
                maxSplits = max(maxSplits, 1 + backtrack(s, i + 1, seen));
                seen.erase(current);
            }
        }

        return maxSplits;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(s, 0, seen);
    }
};