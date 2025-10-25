class Solution {
public:
    int oneWeekMoney(int first, int& n) {
        int ans = 0;
        int temp = n;
        for (int day = 1; day <= temp && day <= 7; day++) {
            ans += first;
            first++;
            n--;
        }

        return ans;
    }
    int totalMoney(int n) {
        int mondayDeposit = 1;
        int ans = 0;
        while (n > 0) {
            ans += oneWeekMoney(mondayDeposit, n);
            mondayDeposit++;
        }
        return ans;
    }
};