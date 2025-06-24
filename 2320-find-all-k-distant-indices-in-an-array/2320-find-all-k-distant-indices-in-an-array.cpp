class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& arr, int key, int k) {
        int n = arr.size();
        vector<int> ans;
        for(int i =0 ;i<n;i++){
            for(int j = 0;j<n;j++){
                if(abs(i-j)<=k){
                    if(arr[j]==key){
                        if(find(ans.begin(),ans.end(),i)==ans.end())
                        ans.push_back(i);
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};