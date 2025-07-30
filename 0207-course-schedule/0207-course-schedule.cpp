class Solution {
public:
    bool isCycle(vector<vector<int>>& adj, int v) {
        vector<int> inDegree(v, 0);
        for (int u = 0; u < adj.size(); u++) {
            for (int neighbour : adj[u]) {
                inDegree[neighbour]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto child : adj[node]) {
                inDegree[child]--; 
                if (inDegree[child] == 0) {
                    q.push(child);
                }
            }
        }

        return count != v; 
    }

    bool canFinish(int v, vector<vector<int>>& prere) {
        vector<vector<int>>adj(v);
        for(auto p: prere){
            adj[p[1]].push_back(p[0]);
        }
        return !isCycle(adj, v);
    }
};
