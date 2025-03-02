class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        map<int,int>freq;
        for(auto list: nums1){
            freq[list[0]]+=list[1];
        }
        for(auto list: nums2){
            freq[list[0]]+=list[1];
        }

        for(pair<int,int>p:freq){
            ans.push_back({p.first,p.second});
        }
        return ans;
    }
};