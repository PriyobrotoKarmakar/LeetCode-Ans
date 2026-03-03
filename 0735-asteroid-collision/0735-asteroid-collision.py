class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        ans = []
        for i in range(len(asteroids)):
            curr = asteroids[i]
            alive = True
            while (alive and (len(stack) > 0) and (stack[-1] > 0) and (curr < 0)):
                # if both are same
                if stack[-1] == abs(curr):
                    stack.pop()
                    alive = False
                elif stack[-1] < abs(curr):
                    stack.pop()
                else:
                    alive = False

            if alive == True:
                stack.append(curr)

        while len(stack) > 0:
            ans.append(stack[-1])
            stack.pop()

        ans.reverse()

        return ans
