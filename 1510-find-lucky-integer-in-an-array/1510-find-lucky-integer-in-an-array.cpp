class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> luckyFreq;
        for(auto ele: arr){
            luckyFreq[ele]++;
        }
        int maxCheck = -1;
        for(auto P: luckyFreq){
            if(P.first == P.second){
                maxCheck = max(maxCheck,P.first);
            }
        }
        return maxCheck;
    }
};