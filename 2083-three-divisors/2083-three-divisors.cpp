class Solution {
public:
    bool countDiv(int n){
        int count = 2;
        for(int i = 2;i*i<=n;i++){
            if(n%i==0 && i*i!=n){
                count+=2;
            }else if(n%i==0){
                count++;
            }
            if(count>3) return false;
        }
        return count==3;
    }
    bool isThree(int n) {
        return countDiv(n);
    }
};