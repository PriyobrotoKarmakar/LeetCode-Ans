class Solution {
public:
    vector<int> diffWaysToCompute(string str) {
        vector<int>ans;
        for(int i=0;i<str.size();i++){
            if(str[i]=='+' or str[i]=='-' or str[i]=='*'){
                vector<int>left = diffWaysToCompute(str.substr(0,i));
                vector<int>right = diffWaysToCompute(str.substr(i+1));

                for(auto x:left){
                    for(auto y:right){
                        if(str[i]=='+') ans.push_back(x+y);
                        if(str[i]=='-') ans.push_back(x-y);
                        if(str[i]=='*') ans.push_back(x*y);
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(str));
        return ans;
    }
};