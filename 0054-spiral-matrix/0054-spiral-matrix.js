/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    let ans = [];
    let id = 0;
    let left = 0;
    let right = matrix[0].length - 1;
    let up = 0;
    let down = matrix.length - 1;

    while (up <= down && left <= right) {
        if (id === 0) {
            for (let i = left; i <= right; i++) {
                ans.push(matrix[up][i]);
            }
            up++;
        } else if (id === 1) {
            for (let i = up; i <= down; i++) {
                ans.push(matrix[i][right]);
            }
            right--;
        } else if (id === 2) {
            for (let i = right; i >= left; i--) {
                ans.push(matrix[down][i]);
            }
            down--;
        } else {
            for (let i = down; i >= up; i--) {
                ans.push(matrix[i][left]);
            }
            left++;
        }
        id = (id + 1) % 4;
    }

    return ans;
};
