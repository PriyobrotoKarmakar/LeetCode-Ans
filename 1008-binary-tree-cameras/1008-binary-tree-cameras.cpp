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
    int ans = 0;
    int solve(TreeNode* root) {
        if (root == NULL)
            return 1;
        int leftChild = solve(root->left);
        int rightChild = solve(root->right);

        if (leftChild == 0 || rightChild == 0) {
            ans++;
            return 2;
        }
        if (leftChild == 2 || rightChild == 2)
            return 1;
        return 0;
    }
    int minCameraCover(TreeNode* root) {
        if (solve(root) == 0)
            ans++;
        return ans;
    }
};