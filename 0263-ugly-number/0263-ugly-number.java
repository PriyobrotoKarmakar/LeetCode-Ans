class Solution {
    public boolean isUgly(int n) {
        while(n>0){
            if((n&1)==0){
                n/=2;
            }
            else if(n%3==0){
                n/=3;
            }
            else if(n%5==0){
                n/=5;
            }
            else{
                break;
            }
        }
        return n==1;
    }
}