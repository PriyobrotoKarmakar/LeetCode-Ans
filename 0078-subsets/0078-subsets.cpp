class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int upperBound = pow(2,n);
        vector<vector<int>> res;
        for(int i= 0;i<upperBound;i++){
            int mask = i;
            int pos = -1;
            vector<int> ans;
            while(mask!=0){
                pos++;
                if(mask&1){
                    ans.push_back(nums[pos]);
                }
                mask>>=1;
            }
            res.push_back(ans);
        }

        return res;

    }
};