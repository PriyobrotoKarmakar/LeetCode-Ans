class Solution {
public:
    void solve(vector<int>& derived, vector<int>& org, int &n) {
        for (int i = 0; i < n - 1; i++) {
            org[i + 1] = org[i] ^ derived[i];
        }
    }
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> org(n);
        org[0] = 0;

        solve(derived,org,n);

        if ((org[0] ^ org[n - 1]) == derived[n - 1]) {
            return true;
        }

        org[0] = 1;

        solve(derived,org,n);

        return ((org[0] ^ org[n - 1]) == derived[n - 1]);
    }
};