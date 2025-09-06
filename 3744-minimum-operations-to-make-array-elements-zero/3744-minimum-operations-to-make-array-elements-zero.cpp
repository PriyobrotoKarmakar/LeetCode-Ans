#define ll long long
class Solution {
public:
    ll solve(int& l, int& r) {
        ll L = 1;
        ll S = 1;
        ll res = 0;
        while (L <= r) {
            ll R = L * 4 - 1;
            ll start = max(L, (ll)l);
            ll end = min(R, (ll)r);
            if (start <= end) {
                ll ele = end - start + 1;
                res += (ele * S);
            }
            L = L * 4;
            S++;
        }
        return res;
    }
    ll minOperations(vector<vector<int>>& queries) {
        ll steps = 0;
        for (auto& query : queries) {
            int l = query[0];
            int r = query[1];
            steps += (solve(l, r)+1 )/2;
        }
        return steps;
    }
};