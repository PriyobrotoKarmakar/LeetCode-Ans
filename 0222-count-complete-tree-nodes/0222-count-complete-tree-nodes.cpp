/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     void solve(TreeNode* root,int& ans){
        if(root==NULL)return;
        ans += 1;
        if(root->left!=NULL)solve(root->left,ans);
        if(root->right!=NULL)solve(root->right,ans);
     }
    int countNodes(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};