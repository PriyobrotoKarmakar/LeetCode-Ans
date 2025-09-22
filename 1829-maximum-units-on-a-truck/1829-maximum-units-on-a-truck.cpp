class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) { return a[1] > b[1]; }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int cap = truckSize;
        int ans = 0;
        sort(boxTypes.begin(), boxTypes.end(), comp);
        for (auto box : boxTypes) {
            if (cap >= box[0]) {
                ans += (box[0] * box[1]);
                cap -= box[0];
            } else {
                ans += cap * box[1];
                break;
            }
        }

        return ans;
        return 0;
    }
};