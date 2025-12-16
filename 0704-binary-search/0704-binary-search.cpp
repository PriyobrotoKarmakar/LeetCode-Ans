class Solution {
public:
    int binarySearch(vector<int>& arr,int start,int end,int key){
        if(start>end) return -1;

        int mid = start + (end-start)/2;

        if(arr[mid]==key) return mid;
        if(arr[mid]>key) return binarySearch(arr,start,mid-1,key);
        if(arr[mid]<key) return binarySearch(arr,mid+1,end,key);

        return -1;
        
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }
};