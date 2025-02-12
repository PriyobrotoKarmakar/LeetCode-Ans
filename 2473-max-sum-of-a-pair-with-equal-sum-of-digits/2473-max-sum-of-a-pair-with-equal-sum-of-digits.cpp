class Solution {
public:
    int digits(int ele) {
        int sum = 0;
        while (ele) {
            sum += ele % 10;
            ele /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = -1;
        for (int ele : nums) {
            int digitSum = digits(ele);
            if (mp.count(digitSum)) {
                ans = max(ans, ele + mp[digitSum]);
            }
            mp[digitSum] = max(mp[digitSum], ele);
        }
        return ans;
    }
};