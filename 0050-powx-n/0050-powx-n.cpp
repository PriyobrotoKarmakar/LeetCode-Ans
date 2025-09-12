class Solution {
public:
    double MOD = 1e9 + 7;
    double myPow(double a, long long b) {
        int n = b;
        b = (b < 0) ? b * -1LL : b;
        double ans = 1.0;
        while (b != 0) {
            if (b % 2 == 1) {
                ans = (ans * a);
                b--;
            } else {
                a = (a * a);
                b = b / 2;
            }
        }

        return (n < 0) ? 1.0 / ans : ans;
    }
};