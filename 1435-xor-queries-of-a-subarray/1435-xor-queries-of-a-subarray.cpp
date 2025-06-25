class Solution {
public:
    void solve(vector<int>& ans,int start,int end,vector<int>preXOR){
        int temp = preXOR[end+1] ^ preXOR[start];
        ans.push_back(temp);
    }
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = arr.size();
        vector<int>preXOR(n+1,0);
        preXOR[0] = arr[0];
        for(int i = 1;i<=n;i++){
            preXOR[i] = preXOR[i-1] ^ arr[i-1];
        }
        for(auto q: queries){
            solve(ans,q[0],q[1],preXOR);
        }
        return ans;
    }
};