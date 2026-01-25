class Solution {
public:
    bool isValid(string number) {
        int n = number.length();
        if (n == 1)
            return true;
        if (n == 2 || n == 3) {
            if (number[0] == '0')
                return false;
            int num = stoi(number);
            return num <= 255;
        }
        return false;
    }
    void solve(string& s, int i, string number,int parts, vector<string>& ans) {
        // base
        if (parts > 4)
            return;
        if (parts == 4 && i == s.length()) {
            number.pop_back();
            ans.push_back(number);
            return;
        }
        cout<<number<<"->";
        if (i + 1 <= s.length() && isValid(s.substr(i, 1)))
            solve(s, i + 1, number + s.substr(i, 1) + ".", parts + 1, ans);

        if (i + 2 <= s.length() && isValid(s.substr(i, 2)))
            solve(s, i + 2, number + s.substr(i, 2) + ".", parts + 1, ans);

        if (i + 3 <= s.length() && isValid(s.substr(i, 3)))
            solve(s, i + 3, number + s.substr(i, 3) + ".", parts + 1, ans);
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int index = 0,parts = 0;
        string number = "";
        solve(s, index, number, parts, ans);
        return ans;
    }
};