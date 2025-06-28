class Solution {
public:
    using int2=pair<int, int>;
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int2> nidx(n);
        for(int i=0; i<n; i++)
            nidx[i]={nums[i], i};
        nth_element(nidx.begin(), nidx.begin()+k, nidx.end(), greater<int2>());
        sort(nidx.begin(), nidx.begin()+k, [](int2& x, int2& y){ return x.second<y.second;});
        vector<int> ans(k);
        for(int i=0; i<k; i++) ans[i]=nidx[i].first;
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();