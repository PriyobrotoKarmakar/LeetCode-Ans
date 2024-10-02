class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp;
        temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> rank;
        int R = 1;
        for (auto ele : temp) {
            if (rank[ele] == 0) {
                rank[ele] = R++;
            }
        }
        temp.clear();
        for (auto ele : arr) {
            temp.push_back(rank[ele]);
        }
        return temp;
    }
};