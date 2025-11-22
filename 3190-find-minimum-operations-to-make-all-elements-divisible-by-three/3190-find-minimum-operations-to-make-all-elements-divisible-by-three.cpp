class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count= 0;
        for(auto N: nums){
            if(N%3!=0){
                // if(((N-1)%3==0) or ((N+1)%3==0)){
                //     count++;
                // }
                count++;
            }
        }
        return count;
    }
};