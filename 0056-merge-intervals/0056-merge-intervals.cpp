class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        {
            for (vector<int> ele : arr) {
                if (ans.empty() || ans.back()[1] < ele[0]) {
                    ans.push_back(ele);
                }else{
                    ans.back()[1] = max(ans.back()[1],ele[1]);
                }
            }
        }
        return ans;
    }
};