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
    class info {
    public:
        int minVal;
        int maxVal;
        int sum;
        bool isBST;
    };

    info solve(TreeNode* root, int& sum) {
        // base case;
        if (root == NULL) {
            info temp;
            temp.minVal = INT_MAX;
            temp.maxVal = INT_MIN;
            temp.sum = 0;
            temp.isBST = true;
            sum = max(sum, temp.sum);
            return temp;
        }
        if (root->left == NULL and root->right == NULL) {
            info temp;
            temp.minVal = root->val;
            temp.maxVal = root->val;
            temp.sum = root->val;
            temp.isBST = true;
            sum = max(sum, temp.sum);
            return temp;
        }
        info leftAns = solve(root->left, sum);
        info rightAns = solve(root->right, sum);

        info curr;
        curr.minVal = min(leftAns.minVal, min(rightAns.minVal, root->val));
        curr.maxVal = max(root->val, max(leftAns.maxVal, rightAns.maxVal));
        curr.sum = root->val + leftAns.sum + rightAns.sum;
        curr.isBST =
            (leftAns.isBST && 
            rightAns.isBST && 
            leftAns.maxVal < root->val &&
             rightAns.minVal > root->val);
        if (curr.isBST)
            sum = max(sum, curr.sum);

        return curr;
    }

    int maxSumBST(TreeNode* root) {
        int sum = 0;
        info temp = solve(root, sum);
        return sum;
    }
};