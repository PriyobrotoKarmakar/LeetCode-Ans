class Solution:
    def isHappy(self, n: int) -> bool:
        result = 0
        stored_nums = []
        while(result != 1):
            result = sum_of_squares(n)
            if result not in stored_nums:
                stored_nums.append(result)
                n = result
            else:
                return False
        return True


def sum_of_squares(p):
        return sum(int(digit) ** 2 for digit in str(p))