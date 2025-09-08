class Solution {
public:
    bool check(int num) {
        while (num) {
            if (num % 10 == 0)
                return false;
            num /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int a = 1;
        int b = n - 1;

        while (a <= b) {
            if (check(a) && check(b)) {
                return {a, b};
            }
            a++;
            b--;
        }

        return {};
    }
};