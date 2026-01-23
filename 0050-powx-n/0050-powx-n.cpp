class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0)
            N = -N;

        double ans = 1.0;

        while (N > 0) {
            if (N % 2 == 1) {
                ans *= x;
                N--;
            } else {
                x *= x;
                N /= 2;
            }
        }

        return (n < 0) ? 1.0 / ans : ans;
    }
};