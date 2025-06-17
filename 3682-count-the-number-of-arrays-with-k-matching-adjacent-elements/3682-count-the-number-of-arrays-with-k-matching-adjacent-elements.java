class Solution {
    private final int MOD = 1000000007; // \U0001f31f Super important number! Like the "secret sauce" for calculations. Prevents numbers from getting too HUGE and messing things up.

    private static final int MAX_SIZE = 100000; // \U0001f4cf How big can our arrays be? This sets the limit.
    private static final int[] FACTORIALS = new int[MAX_SIZE]; // \U0001f382 This array stores factorials (1*2*3*...*n) to speed up calculations. Like having a cheat sheet.

    public int countGoodArrays(int n, int m, int k) {
        // n = length of array, m = possible numbers, k = times the next number changes

        if (FACTORIALS[0] == 0) { // \U0001f914 Have we calculated factorials before? (Optimization!)
            FACTORIALS[0] = 1; // 0! is always 1.  Like a default setting.
        }

        // This is the core formula! \U0001f9d9‍♂️
        // m * (m-1)^(n-1-k) * C(n-1, k)  all taken MOD
        // It's like a magic spell to calculate the number of good arrays! ✨

        long result = (long) m * power(m - 1, n - 1 - k) % MOD * combinations(n - 1, k) % MOD; // Apply the formula, step by step, making sure not to overflow!
        return (int) result; // Boom! \U0001f389  Here's the answer, cast to integer type.
    }

    // Power Function : Calculates base raised to exponent (base^exponent) modulo MOD \U0001f680
    private long power(int base, int exponent) {
        long res = 1; // Starting point. It's like 1 in multiplication.

        long b = base; // Use a local variable to avoid changing the original base

        while (exponent > 0) { // Keep going as long as exponent is greater than 0
            if ((exponent & 1) == 1) { // If exponent is odd
                res = res * b % MOD; // Multiply result by base
            }
            b = b * b % MOD;   // Take Square of base
            exponent >>>= 1;    // Divide the Exponent by two.
        }
        return res; // Return result
    }


    // Combination Function: Calculates C(a, b)  combinations modulo MOD 组合数 ➗
    private long combinations(int a, int b) {
        // Combinations : Choosing 'b' items out of 'a' without caring about order.

        if (b < 0 || b > a) return 0; // Edge case: No possible combinations if b is invalid

        //Combination function a!/(b! * (a - b)!) all taken mod
        return (long) factorial(a) * inverse(factorial(a - b)) % MOD * inverse(factorial(b)) % MOD;
    }

    // Factorial Function: Calculates factorial of a number  a! \U0001f522
    private int factorial(int a) {
        //Factorial
        if (FACTORIALS[a] != 0) {  // Have we calculated this factorial before?
            return FACTORIALS[a];   // If yes, return it from memory. \U0001f9e0
        }

        for(int i = 1; i <= a; ++i){
            if(FACTORIALS[i] == 0){
              FACTORIALS[i] = (int) ((long)FACTORIALS[i - 1] * i % MOD);
            }
        }
        return FACTORIALS[a]; // Cache factorial
    }


    // Modular Inverse Function: Finds the modular inverse of a number modulo MOD \U0001f504
    private long inverse(long a) {
        //Modular Inverse Function
        if (a == 1) {
            return a; // Base case: inverse of 1 is 1
        }

        //Extended Euclidean algorithm to determine modular Inverse.
        return MOD - MOD / a * inverse(MOD % a) % MOD;
    }
}