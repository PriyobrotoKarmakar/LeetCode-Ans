class Solution {
public:
    bool possible(vector<int>& arr, int day, int bouque, int adj) {
        int count = 0, noOfB = 0;
        for (int i = 0; i < arr.size(); i++) {
            if(arr[i]<=day){
                count++;
            }else{
                noOfB+=(count/adj);
                count  = 0;
            }
        }
        noOfB+=(count/adj);
        return noOfB>=bouque;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (possible(bloomDay, mid, m, k)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};