class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;

        unordered_set<int> st;
        long long ans = 0;
        long long windowSum = 0;

        while (j < n) {
            while (st.count(nums[j])) {
                windowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            windowSum += nums[j];
            st.insert(nums[j]);

            if(j-i+1 == k){
                ans = max(ans,windowSum);
                windowSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};