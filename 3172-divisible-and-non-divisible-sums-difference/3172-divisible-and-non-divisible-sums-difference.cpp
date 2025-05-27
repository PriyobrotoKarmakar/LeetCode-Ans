class Solution {
public:
    int differenceOfSums(int n, int m) {
        int notDivisible = 0;
        int divisible = 0;
        for(int i = 1;i<=n;i++){
            if(i%m == 0){
                divisible += i;
            }else{
                notDivisible += i;
            }
        }

        return notDivisible - divisible;
    }
};