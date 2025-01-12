class Solution {
public:
    void sumOfNext(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result(n);
        int sum = 0;
        // first window
        for (int m = 0, j = 1; m < k; m++, j = (j + 1) % n) {
            sum += arr[j];
        }
        result[0] = sum;

        for (int m = 1, i = 1, j = (k + 1) % n; m < n; m++,
             j = (j + 1) % n, i = (i + 1) % n) {
        
                sum-=arr[i];
                sum+=arr[j];

                result[m] = sum;
        }
        arr = result;
    }
    void sumOfPrev(vector<int>& arr, int k) {
        vector<int> ans;
        ans = arr;
        int n = arr.size();
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=1;j<=k;j++){
        //         if((i-j)<0){
        //             sum+=arr[n+(i-j)];
        //         }else{
        //             sum+=arr[i-j];
        //         }
        //     }
        //     ans[i] = sum;
        // }
        int i = n - 2;
        int j = n - 2;
        int sum = 0;
        for (int m = 0; m < k; m++) {
            sum += arr[j];
            j = (j - 1) < 0 ? n + (j - 1) : j - 1;
        }
        ans[n - 1] = sum;
        for (int m = n - 2; m >= 0; m--) {
            sum -= arr[i];
            i = (i - 1) < 0 ? n + (i - 1) : i - 1;
            sum += arr[j];
            j = (j - 1) < 0 ? n + (j - 1) : j - 1;
            ans[m] = sum;
        }
        arr = ans;
    }
    vector<int> decrypt(vector<int>& code, int k) {
        if (k == 0) {
            for (int i = 0; i < code.size(); i++) {
                code[i] = 0;
            }
        } else if (k > 0) {
            sumOfNext(code, k);
        } else {
            sumOfPrev(code, (-1) * k);
        }
        return code;
    }
};