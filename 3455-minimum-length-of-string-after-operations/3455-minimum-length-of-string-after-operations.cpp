class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int> freq;
        int ans = 0;
        for(char ch: s){
            freq[ch]++;
        }
        for(const pair<char,int>p : freq  ){
            int temp = p.second;
            while(temp>=3){
                temp-=2;
            }
            ans+=temp;
        }
        return ans;
    }
};