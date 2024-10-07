class Solution {
public:
//     int minLength(string s) {
//         stack<char> st;
//         for(int i=0;i<s.length();i++){
//         if (!st.empty() and ((st.top() == 'A' and s[i] == 'B') or
//                        (st.top() == 'C' and s[i] == 'D'))) {
//                 st.pop();
//             } else {
//                 st.push(s[i]);
//             }
//     }   
// return st.size();
//     }
int minLength(string s){
        int i = 0;
        int j = 1;
        while (j < s.length()) {
            if (i < 0) {
                s[++i] = s[j];
            } else if ((s[i] == 'A' and s[j] == 'B') or
                       (s[i] == 'C' and s[j] == 'D')) {
                i--;
            } else {
                s[++i] = s[j];
            }
            j++;
        }
        return i + 1;
    }
};
