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
    void mapping(vector<int>& inorder, unordered_map<int, int>& index) {
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
    }
    TreeNode* constructTree(vector<int>& inorder, vector<int>& postorder,
                            int& postorderIndex, int inorderStart,
                            int inorderEnd, unordered_map<int, int>& index) {
        // base case
        if (postorderIndex < 0)
            return NULL;
        if (inorderStart > inorderEnd)
            return NULL;

        // fetchig the post order element;
        int element = postorder[postorderIndex--];
        int eleIndex = index[element];
        TreeNode* root = new TreeNode(element);

        // LRN
        root->right = constructTree(inorder, postorder, postorderIndex,
                                    eleIndex + 1, inorderEnd, index);
        root->left = constructTree(inorder, postorder, postorderIndex,
                                   inorderStart, eleIndex - 1,
                                   index);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> index;
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;
        int postorderIndex = postorder.size() - 1;
        mapping(inorder, index);
        return constructTree(inorder, postorder, postorderIndex, inorderStart,
                             inorderEnd, index);
    }
};