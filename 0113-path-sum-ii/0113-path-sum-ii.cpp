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
    vector<vector<int>> ans;
    void solve(TreeNode* root,int target,vector<int>temp,int sum){
        if(!root)return;
        temp.push_back(root->val);
        sum+=root->val;
        if(root->left==NULL and root->right==NULL){
            if(sum==target){
                ans.push_back(temp);
            }
        }

        solve(root->left,target,temp,sum);
        solve(root->right,target,temp,sum);

        sum-=root->val;
        temp.pop_back();

        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        int sum =0;
        solve(root,targetSum,temp,sum);
        return ans;
    }
};