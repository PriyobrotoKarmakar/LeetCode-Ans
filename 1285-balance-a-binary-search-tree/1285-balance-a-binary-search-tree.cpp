class Solution {
public:
    int height(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int getBalance(TreeNode* root) {
        if (!root) return 0;
        return height(root->left) - height(root->right);
    }

    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        return y;
    }

    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        return x;
    }

    TreeNode* avlTreeInsertion(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);

        if (val < root->val)
            root->left = avlTreeInsertion(root->left, val);
        else if (val > root->val)
            root->right = avlTreeInsertion(root->right, val);
        else
            return root;

        int balance = getBalance(root);


        if (balance > 1 && val < root->left->val)
            return rightRotate(root);

     
        if (balance < -1 && val > root->right->val)
            return leftRotate(root);

        
        if (balance > 1 && val > root->left->val) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

      
        if (balance < -1 && val < root->right->val) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inorderInsert(TreeNode* node, TreeNode*& avlRoot) {
        if (!node) return;
        inorderInsert(node->left, avlRoot);
        avlRoot = avlTreeInsertion(avlRoot, node->val);
        inorderInsert(node->right, avlRoot);
    }

    TreeNode* balanceBST(TreeNode* root) {
        TreeNode* avlRoot = nullptr;
        inorderInsert(root, avlRoot);
        return avlRoot;
    }
};
