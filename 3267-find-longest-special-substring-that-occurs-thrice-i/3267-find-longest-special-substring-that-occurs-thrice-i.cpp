class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string, int> freq;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            string SpacialSubStr = "";
            SpacialSubStr += s[i];
            freq[SpacialSubStr]++;
            for (int j = i + 1; j < n; j++) {
                if (s[j] == s[j - 1]) {
                    SpacialSubStr += s[j];
                    freq[SpacialSubStr]++;
                } else
                    break;
            }
        }
        int result = INT_MIN;
        for (pair<string, int> P : freq) {

            if (P.second >= 3) {
                int temp = P.first.length();
                cout << temp << endl;
                result = max(result, temp);
            }
        }
        return (result == INT_MIN) ? -1 : result;
    }
};