class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int mask = 0;
        for(int i = 0;i<=n;i++){
            mask^=i;
        }

        for(auto ele: nums){
            mask^=ele;
        }
        return mask;
    }
};