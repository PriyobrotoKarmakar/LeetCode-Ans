class Solution {
    vector<int> parent;
    vector<int> size;

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
            size[rootJ] += size[rootI];
        }
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int totalNodes = n * n;
        parent.resize(totalNodes);
        size.assign(totalNodes, 1);
        iota(parent.begin(), parent.end(), 0);

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    int idx = r * n + c;
                    for (int k = 0; k < 4; ++k) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            int nIdx = nr * n + nc;
                            unite(idx, nIdx);
                        }
                    }
                }
            }
        }

        int maxArea = 0;
        bool hasZero = false;

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) {
                    hasZero = true;
                    int currentArea = 1;
                    unordered_set<int> uniqueRoots;

                    for (int k = 0; k < 4; ++k) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                            int root = find(nr * n + nc);
                            if (uniqueRoots.find(root) == uniqueRoots.end()) {
                                currentArea += size[root];
                                uniqueRoots.insert(root);
                            }
                        }
                    }
                    maxArea = max(maxArea, currentArea);
                }
            }
        }

        return hasZero ? maxArea : n * n;
    }
};