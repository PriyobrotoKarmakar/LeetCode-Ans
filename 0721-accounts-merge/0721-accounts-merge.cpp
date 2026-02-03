#include <vector>
#include <string>
#include <numeric>
#include <unordered_map>
#include <algorithm>

using namespace std;

class DSU {
public:
    vector<int> leader;
    DSU(int n) {
        leader.resize(n);
        iota(leader.begin(), leader.end(), 0);
    }
    int find(int i) {
        if (leader[i] == i)
            return i;
        return leader[i] = find(leader[i]);
    }

    void unite(int i, int j) {
        int leader1 = find(i);
        int leader2 = find(j);

        if (leader1 != leader2) {
            leader[leader1] = leader2;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int> emailToID;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (emailToID.find(mail) == emailToID.end()) {
                    emailToID[mail] = i;
                } else {
                    dsu.unite(i, emailToID[mail]);
                }
            }
        }

        unordered_map<int, vector<string>> mergedEmails;
        for (auto& pair : emailToID) {
            string mail = pair.first;
            int id = pair.second;
            int root = dsu.find(id);
            mergedEmails[root].push_back(mail);
        }

        vector<vector<string>> result;
        for (auto& pair : mergedEmails) {
            int root = pair.first;
            vector<string> component = pair.second;
            sort(component.begin(), component.end());
            component.insert(component.begin(), accounts[root][0]);
            result.push_back(component);
        }

        return result;
    }
};