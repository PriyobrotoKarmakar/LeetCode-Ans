class Solution {
public:
    int minSwaps(string s) {
        if(s.length()==0)return 0;

        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(!st.empty() and st.top()=='[' and s[i]==']'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        if(st.empty())return 0;

        int count=0;
        while(!st.empty()){
            if(st.top()=='['){
                count++;
            }
            st.pop();
        }
        return (count+1)/2;
    }
};