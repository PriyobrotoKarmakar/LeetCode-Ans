class Solution {
    public int maximumGain(String s, int x, int y) {
        char[] chars = s.toCharArray();
        int total = 0, a = 0, b = 0;
        char first = x > y ? 'a' : 'b', second = x > y ? 'b' : 'a';
        int max = Math.max(x, y), min = Math.min(x, y);
        
        for (char c : chars) {
            if (c == first) {
                a++;
            } else if (c == second) {
                if (a > 0) {
                    a--;
                    total += max;
                } else {
                    b++;
                }
            } else {
                total += Math.min(a, b) * min;
                a = b = 0;
            }
        }
        return total + Math.min(a, b) * min;
    }
}