class Solution {
public:
    long long dividePlayers(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int i=0,j=arr.size()-1;
        int curr = arr[i]+arr[j];
        long long ans = 0;
        while(i<j){
            if(arr[i]+arr[j]!=curr){
                return -1;
            }
            ans +=(arr[i++]*arr[j--]);

        }
        return ans;
    }
};