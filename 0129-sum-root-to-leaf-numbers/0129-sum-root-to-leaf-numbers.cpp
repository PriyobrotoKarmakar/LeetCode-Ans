class Solution {
public:
    int ans = 0;

    void solve(TreeNode* root, string number) {
        if (!root) return;

        
        number += ('0' + root->val);

        
        if (!root->left && !root->right) {
            ans += stoi(number);
            return;
        }

     
        solve(root->left, number);
        solve(root->right, number);
    }

    int sumNumbers(TreeNode* root) {
        solve(root, "");
        return ans;
    }
};
