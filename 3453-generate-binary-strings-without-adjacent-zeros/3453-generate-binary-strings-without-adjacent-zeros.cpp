class Solution {
public:
    void solve(int i, string& s, vector<string>& ans, int prev) {
        if (i == s.length()) {
            
                ans.push_back(s);
            return;
        }
        if (prev == -1 || s[prev] != '0') {
            s[i] = '0';
            solve(i + 1, s, ans, i);
        }
        s[i] = '1';
        solve(i + 1, s, ans, i);
        
    }
    vector<string> validStrings(int n) {
        string s = "";
        for (int i = 0; i < n; i++) {
            s.push_back('0');
        }

        vector<string> ans;
        solve(0, s, ans,-1);
        return ans;
    }
};