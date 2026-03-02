class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto ele: stones){
            pq.push(ele);
        }

        while(pq.size()>1){
            int first  = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();

            if(first!=second){
                pq.push((first-second));
            }
        }

        if(!pq.empty()) return pq.top();
        return 0;
    }
};