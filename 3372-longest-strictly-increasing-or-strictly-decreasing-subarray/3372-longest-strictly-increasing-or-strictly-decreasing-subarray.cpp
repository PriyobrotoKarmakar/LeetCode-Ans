class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int increasing = 1;
        int incAns = 1;
        int deccreasing = 1;
        int decAns = 1;
        for(int i=0;i<nums.size()-1;i++){
            int first = nums[i];
            int second = nums[i+1];
            if(first<second){
                increasing++;
                incAns = max(incAns,increasing);
            }else{
                increasing = 1;
            }
        }
        for(int i=0;i<nums.size()-1;i++){
            int first = nums[i];
            int second = nums[i+1];
            if(first>second){
                deccreasing++;
                decAns = max(decAns,deccreasing);
            }else{
                deccreasing = 1;
            }
        }
        cout<<decAns<<" "<<incAns;
        
            return max(decAns,incAns);
       
    }
};