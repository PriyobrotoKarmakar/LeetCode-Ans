class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            bool F_isOdd = nums[i]&1;
            bool S_isOdd = nums[i+1]&1;
            if(F_isOdd == S_isOdd)
                return false;
        }
        return true;
    }
};