class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto ele : nums) {
            freq[ele]++;
        }

        priority_queue<pair<int,int>>pq;
        for(auto P: freq){
            pq.push({P.second,P.first});
        }


        vector<int> ans;
        while(k--){
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        return ans;
    }
};