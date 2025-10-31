class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, int> freq;
        for (auto i : nums) {
            freq[i]++;
        }
        vector<int> ans;
        for (auto i : nums) {
            if (freq[i] > 1 and find(ans.begin(), ans.end(), i) == ans.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};