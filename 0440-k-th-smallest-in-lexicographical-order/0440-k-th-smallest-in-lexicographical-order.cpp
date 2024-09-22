class Solution {
public:
    long solve(long n, long prefix, long nextPrefix) {
        long count = 0;
        while (prefix <= n) {
            count += min(n + 1, nextPrefix) - prefix;
            prefix *= 10;
            nextPrefix *= 10;
        }
        return count;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k) {
            long count = solve(n, curr, curr + 1);
            if (count <= k) {
                curr++;
                k -= count;
            } else {
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
};
