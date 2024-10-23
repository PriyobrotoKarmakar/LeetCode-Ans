/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;
        while (!q.empty()) {
            int n = q.size();
            int sum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            // cout<<sum<<endl;
            level.push_back(sum);
        }
        q.push(root);
        root->val = 0;
        int index = 1;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* curr = q.front();
                q.pop();
                int sibSum = curr->left != NULL ? curr->left->val : 0;
                sibSum += curr->right != NULL ? curr->right->val : 0;

                if(curr->left){
                    curr->left->val = level[index]-sibSum;
                    q.push(curr->left);
                }
                if(curr->right){
                    curr->right->val = level[index]-sibSum;
                    q.push(curr->right);
                }
            }
            index++;
        }
        return root;
    }
};