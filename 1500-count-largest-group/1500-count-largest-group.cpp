class Solution {
public:
    int countSumDigit(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int, int> freq;
        for (int i = 1; i <= n; i++) {
            freq[countSumDigit(i)]++;
        }
        int maxi = INT_MIN;
        for (auto p : freq) {
            maxi = max(maxi, p.second);
        }
        int ans = 0;
        for (auto p : freq) {
            if (maxi == p.second)
                ans++;
        }

        return ans;
    }
};