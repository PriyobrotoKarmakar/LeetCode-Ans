import math
class Solution:
    def subarrayLCM(self, nums: List[int], k: int) -> int:
        #lcm(1,5) = 5
        #1 2 3 4 5
        n = len(nums)
        ans = 0
        for i in range(n):
            currLcm = nums[i]
            for j in range(i,n):
                currLcm = math.lcm(currLcm,nums[j])
                if(currLcm==k):
                    ans+=1
        return ans
        
# import math
# class Solution:
#     def subarrayLCM(self, nums: List[int], k: int) -> int:
#         count = 0
#         n = len(nums)
#         for i in range(n):
#             for j in range(i, n):
#                 a = nums[i:j+1]
#                 b = math.lcm(*a)
#                 if b == k:
#                     count += 1
#                 if b > k:
#                     break
#         return count