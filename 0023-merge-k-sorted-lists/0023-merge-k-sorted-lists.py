import heapq
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertAtTail(self,head,tail,nextNode) ->Optional[ListNode]:
        if(head is None and tail is None):
            head = nextNode
            tail = nextNode
        else:
            tail.next = nextNode
            tail = tail.next
        return head,tail
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        minHeap = []
        for i in range(len(lists)):
            if(lists[i]!=None):
                heapq.heappush(minHeap,(lists[i].val,i,lists[i]))

        head = None
        tail = None

        while(len(minHeap)>0):
            val,i,nextNode = heapq.heappop(minHeap)

            head,tail = self.insertAtTail(head,tail,nextNode)

            if(nextNode.next):
                heapq.heappush(minHeap,(nextNode.next.val,i,nextNode.next))

        return head

            
        