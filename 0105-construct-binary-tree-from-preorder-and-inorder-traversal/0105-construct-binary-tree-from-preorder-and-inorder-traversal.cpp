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
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder,
                            int &preorderIndex, int inorderStart, int inorderEnd,
                            unordered_map<int, int>& index) {
        // base case
        if (preorderIndex >= preorder.size())
            return NULL;
        if (inorderStart > inorderEnd)
            return NULL;

        // get the element from preorder

        int element = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(element);
        int inorderIndex = index[element];

        // search space
        root->left = constructTree(preorder, inorder, preorderIndex,
                                   inorderStart, inorderIndex - 1, index);
        root->right = constructTree(preorder, inorder, preorderIndex,
                                    inorderIndex + 1, inorderEnd, index);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> index;
        mapping(inorder, index);
        int preorderIndex = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;
       return  constructTree(preorder,inorder,preorderIndex,inorderStart,inorderEnd,index);
    }
};