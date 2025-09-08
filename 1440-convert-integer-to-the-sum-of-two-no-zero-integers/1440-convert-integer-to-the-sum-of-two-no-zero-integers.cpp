class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = n;
        int b = 0;
        int placeValue = 1;
        while (n > 1) {
            int take = 1;
            if (n % 10 == 1) {
                take = 2;
            }

            a = a - take * placeValue;
            b = b + take * placeValue;

            n = (n - take) / 10;
            placeValue *= 10;
        }
        return {a, b};
    }
};