const int N=256, mask=255, bshift=8;
int freq[N];

void radix_sort(int* nums, int n) {
    int* output = (int*)alloca(n * sizeof(int));  // buffer
    unsigned M=*max_element(nums, nums+n);
    const int Mround = max(1, int(31-countl_zero(M)+bshift)/bshift);
    int* in=nums;
    int* out=output;
    bool swapped=0;

    for (int round=0; round<Mround; round++) {
        const int shift=round*bshift;
        memset(freq, 0, sizeof(freq));

        for (int i = 0; i < n; i++)
            freq[(in[i] >> shift) & mask]++;

        partial_sum(freq, freq+N, freq);

        for (int i = n - 1; i >= 0; i--) {
            int val = in[i];
            int x = (val >> shift) & mask;
            out[--freq[x]] = val;
        }

        swap(in, out);
        swapped = !swapped;
    }

    // If needed, copy back
    if (swapped)
        memcpy(nums, in, n * sizeof(int));
}
class Solution {
public:
    static int largestPerimeter(vector<int>& nums) {
        const int n=nums.size();
        int* A=nums.data();
        radix_sort(A, n);
        for(int i=n-1; i>1; i--){
            if (A[i]<A[i-1]+A[i-2]) 
            return A[i]+A[i-1]+A[i-2];
        }
        return 0;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();