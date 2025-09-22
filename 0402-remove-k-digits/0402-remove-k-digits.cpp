class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        char stack[n];
        int digit = n-k;
        int top = 0;
        for(int i=0;i<n;i++){
            while(top>0 && stack[top-1]>num[i] && k>0){
                top--;
                k--;
            }
            stack[top++] = num[i];
        }
        int posOfStack;
        for(posOfStack=0;posOfStack<digit;posOfStack++ ){

            if(stack[posOfStack]!='0') break;
        }
        if(posOfStack==digit) return "0";
        string ans = "";
        for(int i=posOfStack;i<digit;i++){
            ans+=stack[i];

        }
        return ans;
        
    }
};