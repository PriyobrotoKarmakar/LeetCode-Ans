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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(0);
        ListNode* tail = ans;
        while (list1 != NULL and list2 != NULL) {
            if (list1->val > list2->val) {
                ListNode* curr = new ListNode(list2->val);
                tail->next = curr;
                tail = curr;
                list2 = list2->next;

            } else {
                ListNode* curr = new ListNode(list1->val);
                tail->next = curr;
                tail = curr;
                list1 = list1->next;
            }
        }

        while (list1 != NULL) {
            ListNode* curr = new ListNode(list1->val);
            tail->next = curr;
            tail = curr;
            list1 = list1->next;
        }
        while (list2 != NULL) {
            ListNode* curr = new ListNode(list2->val);
            tail->next = curr;
            tail = curr;
            list2 = list2->next;
        }
        return ans->next;
    }
};