class Solution {
    public int maximumCandies(int[] candies, long k) {
        if (k == 0) return 0; // Edge case: No children
        
        int left = 1, right = 0;
        for (int candy : candies) {
            right = Math.max(right, candy); // Get max candy in a pile
        }

        int result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Count children we can satisfy
            long childrenCount = 0;
            for (int candy : candies) {
                childrenCount += candy / mid;
            }

            if (childrenCount >= k) { // We can distribute at least k children
                result = mid;
                left = mid + 1; // Try for a larger candy per child
            } else {
                right = mid - 1; // Try for a smaller value
            }
        }
        return result;
    }
}