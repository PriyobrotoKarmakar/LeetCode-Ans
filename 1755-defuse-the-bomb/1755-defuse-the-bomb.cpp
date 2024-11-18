class Solution {
public:
    void sumOfNext(vector<int>& arr, int k){
        vector<int>ans;
        ans = arr;
        int n = arr.size();
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=1;j<=k;j++){
                sum+=arr[(i+j)%n];
            }
            ans[i] = sum;
        }
        arr = ans;
    }
    void sumOfPrev(vector<int>& arr, int k){
        vector<int>ans;
        ans = arr;
        int n = arr.size();
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=1;j<=k;j++){
                if((i-j)<0){
                    sum+=arr[n+(i-j)];
                }else{
                    sum+=arr[i-j];
                }
            }
            ans[i] = sum;
        }
        arr = ans;
    }
    vector<int> decrypt(vector<int>& code, int k) {
        if(k==0){
            for(int i=0;i<code.size();i++){
                code[i] = 0;
            }
        }else if(k>0){
            sumOfNext(code,k);
        }else{
            sumOfPrev(code,(-1)*k);
        }
        return code;
    }
};