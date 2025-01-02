class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        for (auto ele : nums) {
            if (ele == 0) {
                ans = max(ans, count);
                count = 0;
            } else {
                count++;
            }
        }
        ans  = max(ans,count);
        return ans;
    }
};