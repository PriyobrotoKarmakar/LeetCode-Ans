class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        prev = 0
        for i in range(0,len(arr)):
            while(prev+1!=arr[i]):
                prev+=1
                k-=1
                if k==0:
                    return prev
            prev = arr[i]
        return prev + k
            