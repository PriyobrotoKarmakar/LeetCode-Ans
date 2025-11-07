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
    int maximumDia = 0;
    int height(TreeNode* root) {
        if (!root)
            return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int currDia = leftHeight + rightHeight;
        maximumDia = max(maximumDia, currDia);

        return max(leftHeight, rightHeight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maximumDia;
    }
};