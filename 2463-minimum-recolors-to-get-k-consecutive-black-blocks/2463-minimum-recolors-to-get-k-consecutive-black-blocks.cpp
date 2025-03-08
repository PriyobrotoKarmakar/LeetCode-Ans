class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int i = 0,j = 0;
        int W = 0;
        int ans = k;


        while(j<n){
            if(blocks[j]=='W') W++;
            if(j-i+1==k){
                ans = min(ans,W);
                if(blocks[i]=='W'){
                    W--;
                }
                i++;
            }
            j++;
        }

        return ans;
    }
};