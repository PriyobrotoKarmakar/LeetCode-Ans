class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        while(n>=1){
            ans+=(4*(n-1));
            n--;
        }
        return ans;
    }
};