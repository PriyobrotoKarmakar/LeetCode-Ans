class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(banned.begin(), banned.end());
        int i = 0;
        int sum = 0;
        vector<int> ans;
        unordered_map<int,bool>presence;
        unordered_map<int,bool>ansPresence;
        for(auto element: banned){
            presence[element] = true;
        }
        for (int j = 1; j <= n; j++) {
            if (presence[j] == false &&
                ansPresence[j] == false) {
                if (sum + j > maxSum)
                    return ans.size();
                sum += j;
                ans.push_back(j);
                ansPresence[j] = true;
            }
        }
        return ans.size();
    }
};