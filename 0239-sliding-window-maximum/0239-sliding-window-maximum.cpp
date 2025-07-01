class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        int n = nums.size();
        vector<int> ans;
        multiset<int> ms;
        
        for (int i = 0; i < n; i++) {
            ms.insert(nums[i]);
            
            if (i - l + 1 == k) {
                // Get maximum element
                ans.push_back(*ms.rbegin());
                
                // Remove the element going out of the window
                ms.erase(ms.find(nums[l]));
                l++;
            }
        }
        
        return ans;
    }
};
