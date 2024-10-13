#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // Min-heap to store the current minimum element from each list
        // Each element in the heap will store {value, index of the list, index in the list}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        int maxInHeap = INT_MIN; // Track the maximum element currently in the heap

        // Initialize the heap with the first element from each list
        for (int i = 0; i < nums.size(); i++) {
            minHeap.push({nums[i][0], i, 0});
            maxInHeap = max(maxInHeap, nums[i][0]);
        }

        int rangeStart = 0, rangeEnd = INT_MAX;

        // Continue until one of the lists is exhausted
        while (true) {
            auto minElement = minHeap.top();
            minHeap.pop();

            int minValue = minElement[0];
            int listIndex = minElement[1];
            int elementIndex = minElement[2];

            // Update the range if we found a smaller one
            if (maxInHeap - minValue < rangeEnd - rangeStart) {
                rangeStart = minValue;
                rangeEnd = maxInHeap;
            }

            // If there are more elements in the current list, push the next element to the heap
            if (elementIndex + 1 < nums[listIndex].size()) {
                int nextValue = nums[listIndex][elementIndex + 1];
                minHeap.push({nextValue, listIndex, elementIndex + 1});
                maxInHeap = max(maxInHeap, nextValue);
            } else {
                // If any list is exhausted, we are done
                break;
            }
        }

        return {rangeStart, rangeEnd};
    }
};
