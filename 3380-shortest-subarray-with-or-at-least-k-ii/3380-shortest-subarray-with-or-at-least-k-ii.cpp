class Solution {
public:
    void update(int val,vector<int>&vec,int data){
        for(int i=0;i<32;i++){
            if(val & (1<<i)){
                vec[i]+=data;
            }
        }
    }
    int decimal(vector<int>& vec){
        int ans = 0;
        for(int i=0;i<32;i++){
            if(vec[i]>0){
                ans |= (1<<i);
            }
        }
        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j = 0;
        int ans = INT_MAX;
        vector<int> vec(32,0);
        while(j<n){
            update(nums[j],vec,1);
            while(i<=j && decimal(vec)>=k){
                update(nums[i],vec,-1);
                // cout<<"yo";
                ans = min(ans,j-i+1);
                i++;
            }

            j++;
        }
        return (ans==INT_MAX) ? -1 : ans;
    }
};