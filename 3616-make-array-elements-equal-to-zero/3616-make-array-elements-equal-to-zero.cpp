class Solution {
public:
    bool processSimulation(vector<int> nums, int start, int moveDir) {
        int size = nums.size();
        while (start >= 0 && start < size) {
            if (nums[start] == 0) {
               
                start += moveDir;
            } else {
                
                nums[start]--;
                moveDir = -moveDir;
                start += moveDir;
            }
        }
        
        for (int value : nums) {
            if (value != 0)
                return false;
        }
        return true;
    }
    int countValidSelections(vector<int>& nums) {
        int size = nums.size();
        int validCount = 0;

        for (int index = 0; index < size; index++) {
            if (nums[index] == 0) {
                
                if (processSimulation(nums, index, 1))
                    validCount++;
                if (processSimulation(nums, index, -1))
                    validCount++;
            }
        }
        return validCount;
    }
};