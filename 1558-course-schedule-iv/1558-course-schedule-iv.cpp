class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        bitset<100> rpath[100]={0};
        vector<char> adj[100];

        char deg[100]={0};// indegree
        for(auto& e: prerequisites){
            char a=e[0], b=e[1];
            adj[a].push_back(b);
            rpath[b][a]=1;
            deg[b]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++)
            if (deg[i]==0) q.push(i);// deg 0 nodes
        
        while(!q.empty()){
            auto i=q.front();
            q.pop();
            for(int j: adj[i]){
                rpath[j]|=rpath[i];
                if (--deg[j]==0) q.push(j);
            }
        }
        const int m=queries.size();
        vector<bool> ans(m, 0);
        for(int i=0; i<m; i++)
            ans[i]=rpath[queries[i][1]][queries[i][0]];
        return ans;
    }
};