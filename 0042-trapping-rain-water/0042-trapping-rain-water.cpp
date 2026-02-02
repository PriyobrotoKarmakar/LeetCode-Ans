class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> left(n);
        vector<int> right(n);

        left[0] = height[0];
        for (int index = 1; index < n; index++) {
            left[index] = max(left[index - 1], height[index]);
        }

        right[n-1] = height[n-1];
        for (int index = n - 2; index >= 0; index--) {
            right[index] = max(right[index + 1], height[index]);
        }
        int ans = 0;
        for (int index = 0; index < n; index++) {
            ans += (min(left[index], right[index]) - height[index]);
        }
        return ans;
    }
};