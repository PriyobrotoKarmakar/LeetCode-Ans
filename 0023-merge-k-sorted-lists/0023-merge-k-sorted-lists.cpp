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
class comparetor {
public:
    bool operator()(ListNode*& a, ListNode*& b) { return a->val > b->val; }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, comparetor> pq;
        int row = lists.size();
        for (int i = 0; i < row; i++) {
            ListNode* temp = lists[i];
            if (temp != NULL) {
                pq.push(temp);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while (!pq.empty()) {
            ListNode* front = pq.top();
            pq.pop();

            // insertingAtTail
            if (head == NULL and tail == NULL) {
                head = front;
                tail = front;
            } else {
                tail->next = front;
                tail = front;
            }

            if (front->next != NULL) {
                pq.push(front->next);
            }
        }

        return head;
    }
};