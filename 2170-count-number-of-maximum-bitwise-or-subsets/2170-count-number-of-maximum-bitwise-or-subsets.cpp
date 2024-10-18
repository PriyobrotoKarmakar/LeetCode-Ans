class Solution {
public:
    int count = 0;
    bool check(vector<int>&subSeq,int& maxor){
        int temp = 0;
        for(auto ele:subSeq){
            temp|=ele;
        }

        return temp==maxor;
    }
    void subsequence(vector<int>&nums,vector<int>&subSeq,int index,int& maxor){
        if(index>=nums.size()){
            if(check(subSeq,maxor)){
                count++;
            }
            return;
        }
        subSeq.push_back(nums[index]);
        subsequence(nums,subSeq,index+1,maxor);

        subSeq.pop_back();


        subsequence(nums,subSeq,index+1,maxor);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        int n= nums.size();
        for(auto ele: nums){
            maxOr|=ele;
        }
        vector<int>subSeq;
        subsequence(nums,subSeq,0,maxOr);
        return count;
    }
};