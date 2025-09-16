class Solution {
public:
    int PowerValue(int n) {
        int count = 0;
        while (n != 1) {
            if (n % 2 == 0)
                n = n / 2;
            else
                n = (3 * n) + 1;

            count++;
        }

        return count;
    }
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> pq;
        for (int i = lo; i <= hi; i++) {
            int powervalue = PowerValue(i);
            pq.push_back({powervalue, i});
        }
        sort(pq.begin(), pq.end());

        return pq[(k - 1)].second;
    }
};
static const int init = [] {
   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();