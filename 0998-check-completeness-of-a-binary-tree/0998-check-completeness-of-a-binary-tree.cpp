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
    bool solve(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        bool nullFlag = false;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL){
                nullFlag = true;
            }else{
                if(nullFlag==true){
                    return false;
                }else{
                    q.push(front->left);
                    q.push(front->right);
                }
            }
        }
        return true;
    }
    bool isCompleteTree(TreeNode* root) {
        return solve(root);
    }
};