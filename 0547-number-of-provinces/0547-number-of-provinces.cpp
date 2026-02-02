#include <vector>
#include <numeric>

using namespace std;

class DSU {
public:
    vector<int> leader;
    
    DSU(int n) {
        leader.resize(n);
        iota(leader.begin(), leader.end(), 0);
    }
    
    int find(int i) {
        if(leader[i] == i) return i;
        return leader[i] = find(leader[i]); 
    }

    void unite(int i, int j) {
        int leader1 = find(i);
        int leader2 = find(j);

        if(leader1 != leader2) {
            leader[leader1] = leader2;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n); 

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    dsu.unite(i, j);
                }
            }
        }

        int provinces = 0;
        for(int i = 0; i < n; i++) {
            if(dsu.leader[i] == i) {
                provinces++;
            }
        }
        
        return provinces;
    }
};