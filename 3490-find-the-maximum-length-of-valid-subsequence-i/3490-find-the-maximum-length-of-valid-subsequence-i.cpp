class Solution 
{
public:
    int maximumLength(vector<int>& nums) 
    {
        // Step 1: Initialize counters
        int evenCount = 0, oddCount = 0;
        int altEven = 0, altOdd = 0;

        // Step 2: Loop through each number
        for (int num : nums) 
        {
            int p = num % 2;  // Step 2: Check parity

            // Step 3: Update counters
            if (p == 0) 
            {
                evenCount++;           // Same-parity subsequence (even)
                altEven = altOdd + 1;  // Alternating sequence ending in even
            } 
            else 
            {
                oddCount++;            // Same-parity subsequence (odd)
                altOdd = altEven + 1;  // Alternating sequence ending in odd
            }
        }

        // Step 4 & 5: Return maximum length
        return max({evenCount, oddCount, altEven, altOdd});
    }
};