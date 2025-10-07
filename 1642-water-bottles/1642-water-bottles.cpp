class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        while(numBottles>=numExchange){
            int left = numBottles % numExchange;
            int refill = numBottles/numExchange;
            res += refill;
            numBottles = refill + left;
        }
        return res;
    }
};