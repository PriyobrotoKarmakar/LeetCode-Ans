class Solution {
public:
    bool P[1000];
    void sieve(){
        fill(P,P+1000,true);
        P[0] = false;
        P[1] = false;
        for(int i=2;i<1000;i++){
            if(P[i]==true){
                for(int j = i*i ;j<1000;j+=i){
                    P[j] = false;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        sieve();
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1])continue;

            for(int p = 2;p<nums[i];p++){
                if(P[p]){
                    if((nums[i]-p)<nums[i+1]){
                        nums[i]-=p;
                        break;
                    }
                }
            }

            if(nums[i]>=nums[i+1])return false;
        }
        return true;
    }
};