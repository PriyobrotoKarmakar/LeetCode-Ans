class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (!st.empty() and st.top() == '(' and s[i] == ')') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        int count=0;
        while(!st.empty()){
            count++;
            st.pop();
        }
        return count;
    }
};