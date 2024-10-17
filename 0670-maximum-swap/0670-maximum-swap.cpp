class Solution {
public:
    // priority_queue<int,vector<int>>pq;

    int maximumSwap(int num) {
        // pq.push(num);
        string N = to_string(num);

        // for(int i=0;i<N.length();i++){
        //     for(int j=i+1;j<N.length();j++){
        //         swap(N[i],N[j]);
        //         pq.push(stoi(N));
        //         swap(N[i],N[j]);
        //     }
        // }
        // return pq.top();
        vector<int> maxRight(10, -1);
        for (int i = 0; i < N.length(); i++) {
            int currDigit = N[i]-'0';
            maxRight[currDigit] = i;
        }

        for(int i=0;i<N.length();i++){
            int currDigit = N[i]-'0';
            for(int j=9;j>currDigit;j--){
                int maxInd = maxRight[j];
                if(maxInd!=-1 && maxInd>i){
                    swap(N[i],N[maxInd]);
                    return stoi(N);
                }
            }
        }
        return num;
    }
};