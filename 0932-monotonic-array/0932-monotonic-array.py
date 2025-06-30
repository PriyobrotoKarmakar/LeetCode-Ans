class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        n = len(nums)
        # monotonic increasing order
        checkIncreasingOrder = True
        for i in range(n - 1):
            curr = nums[i]
            next = nums[i + 1]
            if curr > next:
                checkIncreasingOrder = False
                break
        # monotonic decreasing order
        checkDecreasingOrder = True
        for i in range(n - 1):
            curr = nums[i]
            next = nums[i + 1]
            if curr < next:
                checkDecreasingOrder = False
                break
        if (checkIncreasingOrder == True) or (checkDecreasingOrder == True):
            return True
        else:
            return False
        
