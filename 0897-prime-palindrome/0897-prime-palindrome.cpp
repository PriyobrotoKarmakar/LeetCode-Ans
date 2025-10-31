class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1)
            return false;
        if (num <= 3)
            return true;
        if (num % 2 == 0 || num % 3 == 0)
            return false;
        for (long long i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0)
                return false;
        }
        return true;
    }

    int primePalindrome(int n) {
        if (n >= 8 && n <= 11)
            return 11;
        for (int i = 1; i <= 100000; i++) {
            string s = to_string(i);
            string rev(s.rbegin(), s.rend());

            int num = (int)stol(s + rev.substr(1));
            if (num >= n && isPrime(num))
                return num;
        }
        return -1;
    }
};