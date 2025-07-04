class Solution {
    public char kthCharacter(long k, int[] oper) {
        long l[]=new long[oper.length + 1];
        l[0]=1; // Shuru me sirf "a" hai, so length = 1

        // Har operation ke baad string ki length track karo
        for(int i=0;i<oper.length;i++) {
            if (l[i] > k) {
            // Agar k se zyada ho gaya, toh same length rakho
                l[i + 1] = l[i]; 
            } else {    
            // Nahi toh double karo
                l[i + 1] = 2 * l[i]; 
            }
        }

        long index = k - 1; // 0-based indexing
        int nthHalf = 0; // Kitni baar type-1 (shift) ke second half me tha

        // Ab ulta chalte hai — last operation se start karke pehle tak
        for (int i = oper.length - 1; i >= 0; i--) {
            long half = l[i];
            if (index >= half) {
                index -= half; 
                // Second half me tha → first me shift karo
                if (oper[i] == 1) {
                    nthHalf++; 
                // Shift operation tha → character increment hoga
                }
            }
            // Agar first half me tha, toh kuch nahi karna
        }

        // nthHalf baar 'a' ko shift karo
        return (char) ('a' + nthHalf % 26);
    }
}