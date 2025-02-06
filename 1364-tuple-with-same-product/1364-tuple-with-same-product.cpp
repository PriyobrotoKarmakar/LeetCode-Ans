class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                freq[nums[i]*nums[j]]++;
            }
        }
        int totalTouple = 0;
        for(auto it:freq){
            int frequancy = it.second;
            totalTouple += frequancy * (frequancy - 1)/2;
        }
        return totalTouple*8;
        
    }
};