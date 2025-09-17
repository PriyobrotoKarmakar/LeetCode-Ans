class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = INT_MIN;
        
        for(auto ele: left){
            ans = max(ans,ele);
        }
        for(auto ele: right){
            ans = max(ans,n-ele);
        }
        return ans;
    }
};