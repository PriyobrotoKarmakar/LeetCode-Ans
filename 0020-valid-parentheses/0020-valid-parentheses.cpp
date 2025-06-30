class Solution {
public:
    bool check(stack<char>& st, char ch){
        if(!st.empty()){
            if(st.top()=='(' && ch==')')
                return true;
            else if(st.top()=='{' && ch=='}')
                return true;
            else if(st.top()=='[' && ch==']')
                return true;
            else return false;
        }
        return false;

    }
    bool isValid(string s) {
        stack<char> st;
        for(char ch: s){
            if(check(st,ch)){
                st.pop();
            }else{
                st.push(ch);
            }
        }

        return st.empty();
    }
};