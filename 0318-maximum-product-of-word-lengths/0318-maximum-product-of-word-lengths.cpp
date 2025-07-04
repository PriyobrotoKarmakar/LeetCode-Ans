class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n);
        for (int i = 0; i < n; i++) {
            int smallMask = 0;
            for (char ch : words[i]) {
                smallMask = smallMask | (1 << (ch - 'a' + 1));
            }
            mask[i] = smallMask;
        }
        int ans= 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if((mask[i] & mask[j])==0){
                    int lengths = words[i].length() * words[j].length();
                    ans = max(ans,lengths);
                }
            }
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();