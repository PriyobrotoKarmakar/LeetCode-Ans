class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>freq(n+1,0);
        vector<int>ans;

        int count = 0;
        for(int i = 0 ; i< n ; i++){
            if(++freq[A[i]]==2)count++;
            if(++freq[B[i]]==2)count++;
            ans.push_back(count);
        }
        return ans;
    }
};