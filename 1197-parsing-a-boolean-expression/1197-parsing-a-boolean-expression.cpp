class Solution {
public:
    char solve(vector<char>arr,char op){
        switch (op){
            case '!':{
                return arr[0]=='t' ? 'f' : 't'; 
                break;
            }
            case '&':{
                for(char ele:arr){
                    if(ele =='f')return 'f';
                }
                return 't';
                break;
            }
            case '|':{
                for(char ele:arr){
                    if(ele =='t')return 't';
                }
                return 'f';
                break;
            }
        }
        return 't';
    }
    bool parseBoolExpr(string exp) {
        stack<char>st;
        for(int i=0;i<exp.length();i++){
            char curr = exp[i];
            if(curr!=')'){
                if(curr!=',')
                    st.push(curr);
            }else{
                vector<char>temp;
                while(!st.empty() && st.top()!='('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                if(!st.empty()){
                 char tempAns = solve(temp,st.top());
                 st.pop();
                 st.push(tempAns);
                }

            }
        }
        return st.top()=='t' ? true : false;
    }
};