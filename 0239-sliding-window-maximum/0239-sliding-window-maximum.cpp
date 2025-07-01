class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        //first window
        for(int i=0;i<k;i++){
            while(!q.empty() and nums[q.back()]<nums[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        
        ans.push_back(nums[q.front()]);
        
        for(int i=k;i<nums.size();i++){
         
            if(!q.empty() and q.front()==i-k){
                q.pop_front();
            }
           
            while(!q.empty() and nums[q.back()]<nums[i]){
                q.pop_back();
            }
            
            q.push_back(i);
          
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};