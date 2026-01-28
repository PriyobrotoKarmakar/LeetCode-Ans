class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* recAns = removeNodes(head->next);
        if (recAns->val > head->val) {
            return recAns;
        }
        head->next = recAns;
        return head;
    }
};