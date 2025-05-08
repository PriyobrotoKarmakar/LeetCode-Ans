class Solution {
public:
    void reverseSingleWord(string& s){
        int i = 0;
        int j = s.length()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        
    }
    string reverseWords(string s) {
        string ans = "";
        int i = 0 ;
        int j = s.length()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }

        
        string temp = "";
        for(int k = 0;k<s.length();k++){
            if(s[k]!=' '){
                temp+=s[k];
            }else{
                if(temp.length()==0)
                    continue;
                reverseSingleWord(temp);
                ans+=temp;
                ans+=' ';
                temp = "";
            }
        }
        if(temp.length()!=0){
            reverseSingleWord(temp);
                ans+=temp;
        }
        if(ans[ans.length()-1]==' '){
            ans.pop_back();
        }
        return ans;


    }
};