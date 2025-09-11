class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // if (nums.size() == 1)
        //     return 0;
        // if (nums[0] > nums[1])
        //     return 0;
        // if (nums[n - 1] > nums[n - 2])
        //     return n-1;
        int start = 0;
        int end = n - 1;
        while (start < end) {
            int mid =(start+end)/ 2;

            // if (nums[mid] > nums[mid + 1] && nums[mid - 1] < nums[mid]) {
            //     return mid;
             if (nums[mid] < nums[mid + 1]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }
};