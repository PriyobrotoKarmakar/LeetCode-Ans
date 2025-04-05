class Solution {
public:
    int result = 0;
    void solve(vector<int>& nums, int i, vector<int> ans) {
        if (i >= nums.size()) {
            int temp = 0;
            for (auto ele : ans) {
                temp ^= ele;
            }
            result += temp;
            return;
        }

        solve(nums, i + 1, ans);
        ans.push_back(nums[i]);
        solve(nums, i + 1, ans);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<int>ans;
        solve(nums,0,ans);
        return result;

    }
};