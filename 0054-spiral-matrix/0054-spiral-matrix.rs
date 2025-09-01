impl Solution {
    pub fn spiral_order(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let mut ans = Vec::new();
        let mut id = 0;
        let mut left: i32 = 0;
        let mut right: i32 = (matrix[0].len() as i32) - 1;
        let mut up: i32 = 0;
        let mut down: i32 = (matrix.len() as i32) - 1;

        while up <= down && left <= right {
            if id == 0 {
                for i in left..=right {
                    ans.push(matrix[up as usize][i as usize]);
                }
                up += 1;
            } else if id == 1 {
                for i in up..=down {
                    ans.push(matrix[i as usize][right as usize]);
                }
                right -= 1;
            } else if id == 2 {
                for i in (left..=right).rev() {
                    ans.push(matrix[down as usize][i as usize]);
                }
                down -= 1;
            } else {
                for i in (up..=down).rev() {
                    ans.push(matrix[i as usize][left as usize]);
                }
                left += 1;
            }
            id = (id + 1) % 4;
        }

        ans
    }
}
