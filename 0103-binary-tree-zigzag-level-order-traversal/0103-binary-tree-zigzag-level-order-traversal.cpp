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
    void solve(TreeNode* root, vector<vector<int>>& ans) {
        if (!root)
            return;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRightFlag = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> onelevel;

            while (size--) {
                TreeNode* currNode = q.front();
                onelevel.push_back(currNode->val);
                q.pop();
                if (currNode->left) {
                    q.push(currNode->left);
                }
                if (currNode->right) {
                    q.push(currNode->right);
                }
            }
            if (!leftToRightFlag) {
                reverse(onelevel.begin(), onelevel.end());
            }
            leftToRightFlag ^= 1;

            ans.push_back(onelevel);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root, ans);
        return ans;
    }
};