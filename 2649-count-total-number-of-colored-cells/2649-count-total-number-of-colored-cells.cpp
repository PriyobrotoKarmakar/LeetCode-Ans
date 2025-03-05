class Solution {
public:
    long long coloredCells(long long n) {
        long long ans = 1;
        // while(n>=1){
        //     ans+=(4*(n-1));
        //     n--;
        // }
        ans = ans+4*(n*(n-1)/2);
        return ans;
    }
};