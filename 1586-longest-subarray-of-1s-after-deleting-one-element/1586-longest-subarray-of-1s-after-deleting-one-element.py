class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        dp = []
        count = 0

        for num in nums:
            if num == 1:
                count += 1
            else:
                dp.append(count)
                count = 0
        dp.append(count)

        if len(dp) == 1:
            return dp[0] - 1

        max_len = 0
        for i in range(len(dp) - 1):
            max_len = max(max_len, dp[i] + dp[i + 1])

        return max_len