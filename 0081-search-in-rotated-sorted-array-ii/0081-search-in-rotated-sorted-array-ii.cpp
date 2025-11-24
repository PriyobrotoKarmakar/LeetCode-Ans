class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Case 1: Target found
            if (nums[mid] == target) return true;

            // Case 2: Handle Duplicates
            // If low, mid, and high are equal, we can't tell which side is sorted.
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low = low + 1;
                high = high - 1;
                continue; 
            }

            // Case 3: Identify which part is sorted
            
            // Check if Left Half is sorted
            if (nums[low] <= nums[mid]) {
                // Check if target exists in the left half
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1; // Target is in left
                } else {
                    low = mid + 1;  // Target is in right
                }
            }
            // Otherwise, Right Half must be sorted
            else {
                // Check if target exists in the right half
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;  // Target is in right
                } else {
                    high = mid - 1; // Target is in left
                }
            }
        }

        return false;
    }
};