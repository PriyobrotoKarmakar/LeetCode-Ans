class Solution {
public:
    const long long mod=1e9+7;
    int numSub(string& s) {
        long long ans=0, cnt=0;
        for(char c: s){
            cnt= -(c=='1') & (cnt+1);
            ans+= -(c=='1') & cnt;
        }
        return ans%mod;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();