class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> num;
        for(int i = 0;i<n;i++){
            num.push_back({nums[i],i});
        }

        sort(num.begin(),num.end());
        // for(auto ele: num){
        //     cout<<ele.first<<" "<<ele.second<<endl;
        // }

        int i = 0;
        int j = num.size()-1;
        while(i<=j){
            int val1 = num[i].first;
            int val2 = num[j].first;
            // cout<<val1<<"->"<<val2<<endl;
            if((val1+val2) == target){
                
                return {num[i].second,num[j].second};
            }else if((val1+val2)>target){
                j--;
            }else{
                i++;
            }
        }


        // for (int i = 0; i < n; i++) {

        //     for (int j = i+1; j < n; j++) {
        //         if (nums[i] + nums[j] == target)
        //             return {i, j};
        //     }
        // }

        return {};
    }
};