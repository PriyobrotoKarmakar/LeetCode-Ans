class Solution {
public:
    bool isPossible(vector<int>& nums, int maxOperations, int target) {
        int totalOperations = 0;
        for(auto& ele: nums){
            int op = ele/target;
            if((ele%target)==0){
                op-=1;
            }
            totalOperations+=op;
        }
        return totalOperations<=maxOperations;



    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int result = INT_MAX;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(nums, maxOperations, mid)) {
                result = min(result, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};