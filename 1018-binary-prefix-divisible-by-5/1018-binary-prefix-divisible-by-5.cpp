class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        long long int num = 0;
        vector<bool> ans;
        for (int bin : nums) {
            num =( 2 * num + bin)%5;
            ans.push_back(num == 0);
        }
        return ans;
    }
};