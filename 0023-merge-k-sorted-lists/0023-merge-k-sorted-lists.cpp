/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class comperator{
    public:
        bool operator()(ListNode* &a,ListNode* &b){
            return a->val > b->val;
        }
};
class Solution {
    
    void insertAtTail(ListNode* &head,ListNode* &tail,ListNode* &nextNode){
        if(head==NULL and tail==NULL){
            head = nextNode;
            tail = nextNode;
        }else{
            tail->next = nextNode;
            tail = tail->next;
        }
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comperator> pq;

        for(ListNode* head: lists){
            if(head!=NULL) pq.push(head);
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(!pq.empty()){
            ListNode* nextNode = pq.top(); pq.pop();

            insertAtTail(head,tail,nextNode);
            if(nextNode->next!=NULL) pq.push(nextNode->next);
        }
        return head;
    }
};