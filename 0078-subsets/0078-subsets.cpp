class Solution {
public:
    void solve(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans,
               int i = 0) {
        if (i >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(nums, temp, ans, i + 1);
        temp.pop_back();
        solve(nums, temp, ans, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, temp, ans);
        return ans;
    }
};