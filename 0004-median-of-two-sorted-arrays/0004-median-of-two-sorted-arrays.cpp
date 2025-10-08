class Solution {
public:
    double even(vector<int> ans) {
        int s = 0;
        int e = ans.size() - 1;
        int mid = (s + e) >> 1;
        // cout<<ans[mid]<<" "<<ans[mid+1];
        double midean = ((double)ans[mid] + (double)ans[mid + 1]) / 2;
        return midean;
    }
    double odd(vector<int> ans) {
        int s = 0;
        int e = ans.size() - 1;
        int mid = (s + e) >> 1;
        return (double)ans[mid];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        vector<int> arr;
        while (i < nums1.size() and j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            } else {
                arr.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size()) {
            arr.push_back(nums1[i++]);
        }
        while (j < nums2.size()) {
            arr.push_back(nums2[j++]);
        }
        // for(auto i: arr){
        //     cout<<i<<endl;
        // }
        double ans;
        if (arr.size() & 1) {
            ans = odd(arr);
        } else {
            ans = even(arr);
        }
        return ans;
    }
};