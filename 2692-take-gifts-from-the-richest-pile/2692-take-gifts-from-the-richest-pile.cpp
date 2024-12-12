class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int,vector<int>>pq;
        for(auto ele: gifts){
            pq.push(ele);
        }
        while(k--){
            int temp = pq.top();
            pq.pop();
            temp = sqrt(temp);
            pq.push(temp);
        }
        long long ans = 0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};