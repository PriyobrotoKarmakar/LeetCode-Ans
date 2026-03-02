import heapq
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        maxHeap = []
        for ele in stones:
            maxHeap.append(-ele)
        heapq.heapify(maxHeap)


        while(len(maxHeap)>1):
            first = -heapq.heappop(maxHeap)
            second = -heapq.heappop(maxHeap)

            if(first!=second):
                heapq.heappush(maxHeap,-(first-second))

        if maxHeap:
            return -maxHeap[0]

        return 0
            

        