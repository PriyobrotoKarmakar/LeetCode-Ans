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

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();