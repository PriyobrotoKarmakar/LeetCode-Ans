class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        for(int bits=0;bits<32;bits++){
            int count = 0;
            for(auto ele: candidates){
                if((ele & (1<<bits))){
                    count++;
                }
            }
            ans = max(ans,count);
        }
        return ans;
    }
};