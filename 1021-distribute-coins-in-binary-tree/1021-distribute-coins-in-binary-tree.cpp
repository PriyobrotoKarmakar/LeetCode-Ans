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
    int moves;
    int solve(TreeNode* root){
        if(!root) return 0;
        int leftDef = solve(root->left);
        int rightDef = solve(root->right);
        int def = root->val -1 + leftDef + rightDef;

        moves += abs(leftDef) + abs(rightDef);
        return def;

    }
    int distributeCoins(TreeNode* root) {
        solve(root);
        return moves;
        
    }
};