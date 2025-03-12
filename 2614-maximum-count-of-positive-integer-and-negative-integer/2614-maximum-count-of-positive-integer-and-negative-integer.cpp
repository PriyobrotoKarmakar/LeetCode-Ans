class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negCount = 0, zeroCount = 0;
        for(auto ele : nums){
            if(ele>0)break;
            else if(ele==0)zeroCount++;
            else negCount++;
        }
        int posCount= nums.size()-negCount-zeroCount;
        return max(negCount,posCount);
    }
};