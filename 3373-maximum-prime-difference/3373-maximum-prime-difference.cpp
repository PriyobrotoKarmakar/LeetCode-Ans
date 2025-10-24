class Solution {
public:
    bool isPrime(int& num) {
        if(num==1)return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0)
                return false;
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int> primes;
        int first, second;
        for (int i = 0; i < nums.size(); i++) {
            if (isPrime(nums[i])) {
                first = i;
                break;
            }
        }
        for (int i = nums.size() - 1; i > 0; i--) {
            if (isPrime(nums[i])) {
                second = i;
                break;
            }
        }

        return abs(first - second);
    }
};