class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> degree(n, 0);
        vector<int> ans;
        for (auto edge : edges) {
            degree[edge[1]]++;
        }

        for (int i = 0; i < n; i++) {
            if (degree[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};