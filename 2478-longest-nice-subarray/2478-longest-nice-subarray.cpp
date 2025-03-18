class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;

        int result = 1;
        int mask = 0;

        while(j<nums.size()){


            //keep shrinking until i get and = 0;
            while((mask&nums[j])!=0){
                mask = mask^nums[i];
                i++;
            }


            //update result
            result = max(result,j-i+1);
            mask = mask|nums[j];
            j++;
        }


        return result;
    }
};