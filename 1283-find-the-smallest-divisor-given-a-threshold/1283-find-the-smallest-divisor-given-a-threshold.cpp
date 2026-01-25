class Solution {
public:
    bool isValid(vector<int>&nums,int thresshold,int mid){
        int sum = 0;
        for(auto& ele: nums){
            sum+=ceil((double)ele/(double)mid);
        } 
        return sum<=thresshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin(),nums.end());
        int ans = 0;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(isValid(nums,threshold,mid)){
                ans = mid;
                cout<<mid<<"->";
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
    }
};