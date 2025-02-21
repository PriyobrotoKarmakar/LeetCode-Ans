class Solution {
public:
    int countOdds(int low, int high) {
        int temp = high-low;
        int count = 0;
        if(((temp&1)==0) and (high&1) and (low&1)){
            count = (temp/2)+1;
        }else if(((temp&1)==0)){
            count = (temp/2);
        }else{
            count = (temp/2)+1;
        }
        return count;
    }
};