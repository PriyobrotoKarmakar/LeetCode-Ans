class Solution {
public:
    int numberofbits(int n){
        int count = 0;
        while(n>0){
            int mask = n&1;
            if(mask==1){
                count++;
            }
            n>>=1;
        }
        return count;
    }
    bool isPowerOfTwo(int n) {
        if(numberofbits(n)==1){
            return true;
        }
        return false;
    }
};