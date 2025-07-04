class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long  mask = 0;
        for (auto ele : nums) {
            mask ^= ele;
        }
        int pos = 0;
        long long  dupe = mask;
        while (mask != 0) {
            if ((mask & 1) == 1) {
                break;
            }
            mask >>= 1;
            pos ++;
            
        }
        int first = 0;
        int second = 0;
        for(auto ele: nums){
            if(ele & (1<<pos)){
                first ^=ele;
            }else{
                second^=ele;
            }
        }
        
        return {first, second};
    }
};