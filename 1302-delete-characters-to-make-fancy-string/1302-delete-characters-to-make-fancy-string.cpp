class Solution {
public:
    string makeFancyString(string s) {
        // string ans = "";
        // for (int i=0;i<s.length();i++){
        //     char currChar = s[i];
        //     if(ans.length()!=0 and ans[ans.size()-1]==currChar){
        //         char temp = ans[ans.size()-1];
        //         ans.pop_back();
        //         if(ans.length()!=0 and ans[ans.size()-1]==currChar){
        //             ans.pop_back();
        //         }
        //         ans.push_back(temp);
        //     }
        //     ans.push_back(currChar);
        // }
        // return ans;
        int i=0;
        string ans = "";
        while(i<s.length()){
            int j = i-1;
            int k = i-2;
            if(j>=0 and k>=0 and s[j]==s[i] and s[k]==s[i]){
                
            }else{
                ans+=s[i];
            }
            i++;
        }
        return ans;
    }
};