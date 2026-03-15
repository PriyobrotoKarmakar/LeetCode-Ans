import math
class Solution:
    def subarrayLCM(self, nums: List[int], k: int) -> int:
        #lcm(1,5) = 5
        #1 2 3 4 5
        def lcm(firstNumber,secondNumber):
            return (firstNumber*secondNumber)//math.gcd(firstNumber,secondNumber)
        n = len(nums)
        ans = 0
        for i in range(n): #O(n)
            currLcm = nums[i]
            for j in range(i,n): #O(n)
                currLcm = lcm(currLcm,nums[j])
                if(currLcm==k):
                    ans+=1
                elif currLcm > k:
                    break
        return ans
        