class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum = 0;
        priority_queue<int>pq(nums.begin(),nums.end());
        while(k--){
            int maxEle = pq.top();
            pq.pop();
            sum+=maxEle;
            maxEle = ceil(maxEle/3.0);
            pq.push(maxEle);
        }
        return sum;

    }
};