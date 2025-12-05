class Solution {
public:
    multiset<int> ms;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            ms.insert(nums[i]);

            // remove the element which is outof the window
            if (i >= k) {
                auto it = ms.find(nums[i - k]);
                ms.erase(it);
            }

            if (i >= k-1) {
                res.push_back(*ms.rbegin());
            }
        }

        return res;
    }
};