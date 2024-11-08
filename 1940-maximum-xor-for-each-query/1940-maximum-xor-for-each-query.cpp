class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int mask = (1<<maximumBit)-1;
        int totalXor  = 0;
        for(auto ele: nums){
            totalXor^=ele;
        }
        vector<int>ans;
        for(int i=nums.size()-1;i>=0;i--){
            
            int ithTerm = totalXor^(mask);
            ans.push_back(ithTerm);
            totalXor^=nums[i];
        };
        return ans;

    }
};