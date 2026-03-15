import math
class Solution:
    def smallestAbsent(self, nums: List[int]) -> int:
        avg = sum(nums)/len(nums)
        newSet = set(nums)
        start = max(1,math.floor(avg) + 1)
        while start in newSet:
            start += 1
        
        
        return start
            