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
    int getmax(TreeNode* root) {
        while (root->right != NULL) {
            root = root->right;
        }
        return root->val; // Return the rightmost value
    }

    TreeNode* DelNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;

        // Traverse the tree to find the node to delete
        if (key < root->val) {
            root->left = DelNode(root->left, key);
        } else if (key > root->val) {
            root->right = DelNode(root->right, key);
        } else {
            // Node to be deleted found
            if (root->left == NULL) {
                TreeNode* rightN = root->right;
                delete root;
                return rightN; // Return the right subtree
            } else if (root->right == NULL) {
                TreeNode* leftN = root->left;
                delete root;
                return leftN; // Return the left subtree
            } else {
                // Node with two children
                int justmax = getmax(root->left);
                root->val = justmax; // Replace value
                root->left =
                    DelNode(root->left, justmax); // Delete the duplicate node
            }
        }
        return root; // Return the (potentially new) root
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return DelNode(root, key); // Directly call DelNode
    }
};