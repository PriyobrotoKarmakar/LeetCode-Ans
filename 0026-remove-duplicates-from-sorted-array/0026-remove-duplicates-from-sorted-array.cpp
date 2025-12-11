class Solution {
public:
    int solveUsingTwoPointer(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1)
            return n;

        // Start from the second element
        int idx = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[i - 1]) {
                arr[idx++] = arr[i];
            }
        }
        return idx;
    }

    int LinearSearch(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                arr.push_back(nums[i]);
            }
        }
        nums = arr;
        return nums.size();
    }
    int removeDuplicates(vector<int>& nums) { return solveUsingTwoPointer(nums); }
};