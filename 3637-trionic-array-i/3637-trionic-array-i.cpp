class Solution {
private:
    bool strictlyIncreasing(vector<int>& nums, int start, int end) {
        for(int i = start + 1; i <= end; i++) {
            if(nums[i-1] >= nums[i]) return false;
        }
        return true;
    }

    bool strictlyDecreasing(vector<int>& nums, int start, int end) {
        for(int i = start + 1; i <= end; i++) {
            if(nums[i-1] <= nums[i]) return false;
        }
        return true;
    }

public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        for(int p = 1; p <= n - 3; p++) {
            for(int q = p + 1; q < n - 1; q++) {
                bool firstPart = strictlyIncreasing(nums, 0, p);
                bool secondPart = strictlyDecreasing(nums, p, q);
                bool thirdPart = strictlyIncreasing(nums, q, n - 1);

                if(firstPart && secondPart && thirdPart) return true;
            }
        }
        return false;
    }
};