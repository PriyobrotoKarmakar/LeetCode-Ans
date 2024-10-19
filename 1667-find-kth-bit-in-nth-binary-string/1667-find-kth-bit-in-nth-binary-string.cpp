class Solution {
public:
    void makeNext(string& s){
        string temp = s;
        reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            if(temp[i]=='0'){
                temp[i] = '1';
            }else{
                temp[i] = '0';
            }
        }
        s  = s+"1"+temp;
    }
    char findKthBit(int n, int k) {
        string s1 = "0";
        while(--n){
            makeNext(s1);
        }
        return s1[k-1];
    }
};