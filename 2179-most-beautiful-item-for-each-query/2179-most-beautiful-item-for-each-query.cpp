class Solution {
public:
    static bool compareP(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    int solve(vector<vector<int>>& items, int target) {
        int start = 0;
        int end = items.size() - 1;
        int ans = 0;
        while (start <= end) {
            int mid = (start + end) / 2;
            if(items[mid][0]<=target){
                ans = items[mid][1];
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        sort(items.begin(), items.end(), compareP);
        int max = INT_MIN;
        for(int i=0;i<items.size();i++){
            if(max<items[i][1]){
                max = items[i][1];
            }else{
                items[i][1] = max;
            }
        }
        vector<int> ans;
        for (const auto& price : queries) {
            int max= solve(items,price);
            ans.push_back(max);
        }
        return ans;
    }
};