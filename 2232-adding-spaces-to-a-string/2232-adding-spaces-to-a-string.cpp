class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
       queue<int> ind;
       for(auto ele: spaces){
        ind.push(ele);
       }
        string result = "";
        for(int i=0;i<s.length();i++){
            if(!ind.empty() && i==ind.front()){
                result+=' ';
                ind.pop();
            }
                result+=s[i];
        }
        return result;
    }
};