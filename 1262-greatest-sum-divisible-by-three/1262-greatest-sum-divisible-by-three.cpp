class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int totalSum = 0;
        vector<int> r1, r2; // store numbers with remainder 1 and 2

        for (int x : nums) {
            totalSum += x;
            if (x % 3 == 1) r1.push_back(x);
            else if (x % 3 == 2) r2.push_back(x);
        }

        if (totalSum % 3 == 0) return totalSum;

        sort(r1.begin(), r1.end());
        sort(r2.begin(), r2.end());

        int rem = totalSum % 3;
        int ans = 0;

        if (rem == 1) {
            int op1 = (r1.size() >= 1 ? totalSum - r1[0] : 0);
            int op2 = (r2.size() >= 2 ? totalSum - r2[0] - r2[1] : 0);
            ans = max(op1, op2);
        } 
        else { // rem == 2
            int op1 = (r2.size() >= 1 ? totalSum - r2[0] : 0);
            int op2 = (r1.size() >= 2 ? totalSum - r1[0] - r1[1] : 0);
            ans = max(op1, op2);
        }

        return ans;

    }
};