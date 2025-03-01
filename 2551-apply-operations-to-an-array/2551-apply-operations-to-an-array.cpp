class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
            }
        }
        vector<int>ans;
        int zeroCount = 0;
        for(auto ele: nums){
            if(ele!=0){
                ans.push_back(ele);
            }else{
                zeroCount++;
            }
        }

        while(zeroCount--){
            ans.push_back(0);
        }
        return ans;
    }
};