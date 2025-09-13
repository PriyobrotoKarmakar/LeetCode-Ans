class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n = nums.size();
        vector<int> evens, odds;

        for (int i = 0; i < n; i++) {
            if (i % 2 ==  0)
                evens.push_back(nums[i]);
            else
                odds.push_back(nums[i]);
        }
        sort(evens.begin(), evens.end());
        sort(odds.rbegin(), odds.rend());

        vector<int> res;
        int evenIndex = 0, oddIndex = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 ==  0) {
                res.push_back(evens[evenIndex]);
                evenIndex++;
            }

            else {
                res.push_back(odds[oddIndex]);
                oddIndex++;
            }
        }

        return res;
    }
};
