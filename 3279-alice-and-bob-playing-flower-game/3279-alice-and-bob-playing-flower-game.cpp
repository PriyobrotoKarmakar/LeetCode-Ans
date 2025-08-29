class Solution {
public:
    long long flowerGame(int n, int m) {
        long long first = 1LL * ((n + 1) / 2) * (m / 2);
        long long second = 1LL * (n / 2) * ((m + 1) / 2);

        return first + second;
    }
};