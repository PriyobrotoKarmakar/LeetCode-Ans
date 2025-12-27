class Solution:
    def coloredCells(self, n: int) -> int:
        no_of_boxes = n**2 + (n-1)**2
        return no_of_boxes