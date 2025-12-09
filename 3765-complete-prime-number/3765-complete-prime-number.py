class Solution:
    def completePrime(self, num: int) -> bool:
        num_str = str(num)
        #1234566 = 1 12 13 
        for i in range(1,len(num_str)):
            if not is_prime(int(num_str[:i])):
                return False
        #123456  = 6 56 3456
        for j in range(1,len(num_str)+1):
            if not is_prime(int(num_str[-j:])):
                return False
        return True
        #s[-6:]
        
def is_prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3,int(math.sqrt(n))+1,2):
        if n % i == 0:
            return False
    return True