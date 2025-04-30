class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(auto ele: nums){
            if(to_string(ele).length()%2==0){
                count++;
            }
        }
        return count;
    }
};