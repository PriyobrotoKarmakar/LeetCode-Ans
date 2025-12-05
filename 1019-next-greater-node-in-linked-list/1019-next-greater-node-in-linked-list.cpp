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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }

        vector<int> ans(nums.size(), 0);

        stack<int> st;

        for (int i = 0; i < nums.size(); i++) {

            while (!st.empty() && nums[i] > nums[st.top()]) {

                int indexToUpdate = st.top();
                st.pop();

                ans[indexToUpdate] = nums[i];
            }

            st.push(i);
        }

        return ans;
    }
};