class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        vector<int> ans;
        auto first = lower_bound(arr.begin(), arr.end(), target);

        auto last = upper_bound(arr.begin(), arr.end(), target);

        if (first != arr.end() && *first == target) {
            ans.push_back(first - arr.begin());
            ans.push_back(last - arr.begin() - 1);
            return ans;
        }
        return {-1, -1};
    }
};