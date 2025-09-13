#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Bubble sort for even indices (ascending order)
    void bubbleSortEven(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i += 2) {  // start from even indices
            for (int j = 0; j + 2 < n; j += 2) {  // jump 2 steps
                if (nums[j] > nums[j + 2]) {
                    swap(nums[j], nums[j + 2]);
                }
            }
        }
    }

    // Bubble sort for odd indices (descending order)
    void bubbleSortOdd(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i += 2) {  // start from odd indices
            for (int j = 1; j + 2 < n; j += 2) {  // jump 2 steps
                if (nums[j] < nums[j + 2]) { // descending
                    swap(nums[j], nums[j + 2]);
                }
            }
        }
    }

    vector<int> sortEvenOdd(vector<int>& nums) {
        // Apply bubble sort separately
        bubbleSortEven(nums);
        bubbleSortOdd(nums);

        return nums;
    }
};
