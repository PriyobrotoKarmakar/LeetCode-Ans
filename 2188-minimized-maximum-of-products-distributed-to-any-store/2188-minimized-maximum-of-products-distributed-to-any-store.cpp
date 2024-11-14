class Solution {
public:
    bool isSafe(int n,vector<int>& arr,int mid){
        int group = 0;
        for(int ele: arr){
            group += (ele + mid - 1) / mid;
        }
        return group<=n;
    }
    int minimizedMaximum(int n, vector<int>& arr) {
        int s = 1;
        int e = *max_element(arr.begin(),arr.end());
        int ans = e;
        while(s<=e){
            int mid = e - (e-s)/2;
            if(isSafe(n,arr,mid)){
                ans = mid;
                e = mid-1;
            }else{
                
                s = mid+1;
            }
        }
        return ans;
    }
};