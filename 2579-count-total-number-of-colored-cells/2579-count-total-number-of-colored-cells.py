class Solution:
    def coloredCells(self, n: int) -> int:
        ans = 1
        while(n>=1):
            ans+=4*(n-1)
            n-=1
        
        return ans