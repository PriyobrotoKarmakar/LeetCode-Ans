class Solution {
public:
    void moveCharToAns(stack<char>&st,string &ans){
        if(st.empty())
            return;

        char top = st.top();
        st.pop();
        moveCharToAns(st,ans);
        ans+=top;
    }
    string clearDigits(string s) {
        string ans = "";
        stack<char> st;
        for(char ele: s){
            if(ele>='a' and ele<='z'){
                st.push(ele);
            }else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        moveCharToAns(st,ans);
        return ans;
    }
};