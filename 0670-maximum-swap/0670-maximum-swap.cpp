class Solution {
public:
    priority_queue<int,vector<int>>pq;
    
    int maximumSwap(int num) {
        pq.push(num);
        string N = to_string(num);
        
        for(int i=0;i<N.length();i++){
            for(int j=i+1;j<N.length();j++){
                swap(N[i],N[j]);
                pq.push(stoi(N));
                swap(N[i],N[j]);
            }
        }
        return pq.top();
    }
};