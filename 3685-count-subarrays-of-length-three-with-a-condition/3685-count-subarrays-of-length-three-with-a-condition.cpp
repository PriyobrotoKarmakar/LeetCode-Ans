class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i = 0;
        int j = 2;
        int count = 0;
        while(j<nums.size()){
            if((double)(nums[i]+nums[j])==(double)nums[(i+j)/2]/2)
                count++;

            i++;
            j++;
        }
        return count;
    }
};