class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        vector<double> probability(n, 0);
        probability[start] = 1;
        double tmp = 1;
        queue<pair<int, double>> q;
        q.push({start, tmp});

        double ans = 0;
        while(!q.empty())
        {
            int node = q.front().first;
            double prob = q.front().second;
            q.pop();

            probability[node] = max(probability[node], prob);
            for(auto it : adj[node])
            {
                int endP = it.first;
                double thisP = it.second;
                if(thisP * prob > probability[endP])
                {
                    q.push({endP, thisP*prob});
                }
            }
        }

        return probability[end];
    }
};