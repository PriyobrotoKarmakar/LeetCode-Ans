class Solution:
    def coloredCells(self, n: int) -> int:
        ans = 1
        ans = ans + (4 * (n * (n - 1) // 2))  # Use // for integer division
        return int(ans)

        # n==1 => 1(prev)
        # n==2 prev + 4*(n-1) = prev + 4 * 1 =>prev + 4 => 1 + 4 = 5(prev)
        # n==3 prev + 4 * 2 = prev + 8 = > 13
        # n==4  13 + 4 * 3 = 13 + 12 = 25.....
        # n==5 prev + 4 * 4 =
