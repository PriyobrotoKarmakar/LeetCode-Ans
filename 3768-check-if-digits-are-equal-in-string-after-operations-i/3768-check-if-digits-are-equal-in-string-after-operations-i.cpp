class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.length() > 2) {
            string new_s = "";
            for (int i = 0; i < s.length() - 1; i++) {
                new_s += to_string((s[i] - '0' + s[i + 1] - '0') % 10);
            }
            s = new_s;
        }
        cout<<s;
        return s[0] == s[1];
    }
};