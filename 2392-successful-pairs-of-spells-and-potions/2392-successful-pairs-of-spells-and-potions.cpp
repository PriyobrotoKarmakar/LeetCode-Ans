class Solution {
public:
    static inline int binarySearch(int k, vector<int>& potions, int m){
        int l=0, r=m-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(potions[mid]>= k)
                r=mid;
            else
                l=mid+1;
        }
        return l;
    }
    static vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        const int n=spells.size();
        vector<int> result(n, 0);
        
        const int m=potions.size();
        const int maxPotion=potions[m - 1];

        
        for (int i=0; i<n; i++) {
            int spell=spells[i];
            long long k=(success+spell-1)/spell;
            if (k <=maxPotion) {
                result[i]=m-binarySearch(k, potions, m);
            }
        }       
        return result;
    }
};