class Solution {
public:
    void dfs(vector<int>&ans,int n,int curr){
        if(curr>n)return;

        ans.push_back(curr);
        for(int i=0;i<=9;i++){
            dfs(ans,n,(curr*10)+i);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=9;i++){
            dfs(ans,n,i);
        }
        return ans;
    }
};