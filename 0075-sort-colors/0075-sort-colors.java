class Solution {
    public void sortColors(int[] nums) {
        int c1 = 0, c2 = 0, c3 = 0;
        
        // Count 0s, 1s, and 2s
        for (int num : nums) {
            if (num == 0) c1++;
            else if (num == 1) c2++;
            else c3++;
        }

        int idx = 0;

        // Fill 0s
        while (c1-- > 0) {
            nums[idx++] = 0;
        }

        // Fill 1s
        while (c2-- > 0) {
            nums[idx++] = 1;
        }

        // Fill 2s
        while (c3-- > 0) {
            nums[idx++] = 2;
        }
    }
}