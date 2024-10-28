class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<float,int>streak;
        for(int i=0;i<nums.size();i++){
            if(streak[sqrt(nums[i])]!=0){
                streak[nums[i]] = streak[sqrt(nums[i])]+1;
            }else{
                streak[nums[i]]=1;
            }
        }
        int maxi  = INT_MIN;
        for(const pair<float,int>& pair:streak){
            maxi = max(maxi,pair.second);
        }
        if(maxi==1)return -1;

        return maxi;
    }
};