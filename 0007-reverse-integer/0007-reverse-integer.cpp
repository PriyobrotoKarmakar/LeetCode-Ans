class Solution {
public:
    int reverse(long long int x) {
        cout<<INT_MAX<<" "<<x;
        long long int num = 0;
        bool check = (x<0);
        x = abs(x);
        while(x>0){
            int digit = x%10;
            num = (num*10)+digit;
            x/=10;
        }
        num = check? (num*-1):num;
        if(num>INT_MAX || num<INT_MIN) return 0;
        return num;
    }
};