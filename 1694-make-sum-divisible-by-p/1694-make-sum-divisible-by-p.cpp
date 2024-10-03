class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        int remainder = totalSum % p;
        if (remainder == 0) return 0;

        unordered_map<int, int> prefixMap;
        prefixMap[0] = -1; 
        int prefixSum = 0, minLength = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            prefixSum = (prefixSum + nums[i]) % p;
            int target = (prefixSum - remainder + p) % p;

            if (prefixMap.find(target) != prefixMap.end()) {
                minLength = min(minLength, i - prefixMap[target]);
            }

            prefixMap[prefixSum] = i;
        }

        return minLength == nums.size() ? -1 : minLength;
    }
};