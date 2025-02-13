class Solution {
public:
    long int minOperations(vector<int>& nums, int k) {
        priority_queue<long int,vector<long int>,greater<long int>> pq;
        for (auto ele : nums) {
            pq.push(ele);
        }
        long int operation = 0;
        while(pq.size()>=2 and pq.top()<k){
            long int a = pq.top();
            pq.pop();
            long int b = pq.top();
            pq.pop();
            cout<<a<<" "<<b<<endl;
            pq.push(min(a,b)*2 + max(a,b));
            operation++;
        }

        return operation;


    }
};