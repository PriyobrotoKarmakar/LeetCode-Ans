class Solution {
public:
    int fi = 1140;     // Euler's totient of 1337
    int mod = 1337;    // Actual modulus

    long long myPow(long long a, long long b) {
        long long ans = 1;
        a %= mod;   // always reduce base
        while (b != 0) {
            if (b % 2 == 1) {
                ans = (ans * a) % mod;
                b--;
            } else {
                a = (a * a) % mod;
                b /= 2;
            }
        }
        return ans;
    }

    int superPow(long long a, vector<int>& b) {
        // reduce exponent modulo fi(1337)
        int power = 0;
        for (auto ele : b) {
            power = (power * 10 + ele) % fi;
        }

        return myPow(a, power);
    }
};
