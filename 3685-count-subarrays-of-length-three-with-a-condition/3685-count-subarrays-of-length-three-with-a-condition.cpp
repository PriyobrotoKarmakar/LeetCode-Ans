class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i = 0;
        int j = 2;
        int count = 0;
        while(j<nums.size()){
            double firstAndThird = nums[i]+nums[j];
            double middileHalf = (double)nums[(i+j)/2]/2;
            if(firstAndThird == middileHalf)
                count++;

            i++;
            j++;
        }
        return count;
    }
};