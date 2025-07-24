class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n= nums.size();
        int mask = (1<<n);
        vector<vector<int>> ans;
        for(int i= 0;i<mask;i++){
            vector<int>tempAns;
            for(int j=0;j<n;j++){
                if((i>>j)&1){
                    tempAns.push_back(nums[j]);
                }
            }

            ans.push_back(tempAns);
        }

        return ans;
    }
};