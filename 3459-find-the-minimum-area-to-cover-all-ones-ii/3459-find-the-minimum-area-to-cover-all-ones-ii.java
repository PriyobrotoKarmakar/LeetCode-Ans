class Solution {
    public int minimumSum(int[][] grid) {
        // Compute result for grid and for rotated grid, take the minimum
        return Math.min(f(grid), f(rotate(grid)));
    }

    private int f(int[][] a) {
        int m = a.length;
        int n = a[0].length;

        // lr[i][0] = leftmost 1 in row i
        // lr[i][1] = rightmost 1 in row i
        int[][] lr = new int[m][2];
        for (int i = 0; i < m; i++) {
            int l = -1, r = 0;
            for (int j = 0; j < n; j++) {
                if (a[i][j] > 0) {
                    if (l < 0) l = j;
                    r = j;
                }
            }
            lr[i][0] = l;
            lr[i][1] = r;
        }

        // lt[i+1][j+1] = minimum rectangle area covering all 1s
        // in submatrix from (0,0) to (i,j)
        int[][] lt = minimumArea(a);

        a = rotate(a);
        // lb[i][j+1] = minimum rectangle area covering all 1s
        // in submatrix with bottom-left corner at (m-1,0) and top-right corner at (i,j)
        int[][] lb = rotate(rotate(rotate(minimumArea(a))));

        a = rotate(a);
        // rb[i][j] = minimum rectangle area covering all 1s
        // in submatrix with bottom-right corner at (m-1,n-1) and top-left corner at (i,j)
        int[][] rb = rotate(rotate(minimumArea(a)));

        a = rotate(a);
        // rt[i+1][j] = minimum rectangle area covering all 1s
        // in submatrix with top-right corner at (0,n-1) and bottom-left corner at (i,j)
        int[][] rt = rotate(minimumArea(a));

        int ans = Integer.MAX_VALUE;

        // Case 1: split into 3 horizontal parts
        if (m >= 3) {
            for (int i = 1; i < m; i++) {
                int left = n, right = 0, top = m, bottom = 0;
                for (int j = i + 1; j < m; j++) {
                    int l = lr[j - 1][0];
                    if (l >= 0) {
                        left = Math.min(left, l);
                        right = Math.max(right, lr[j - 1][1]);
                        top = Math.min(top, j - 1);
                        bottom = j - 1;
                    }
                    // Divide into: top, middle, bottom
                    ans = Math.min(ans, lt[i][n] + (right - left + 1) * (bottom - top + 1) + lb[j][n]);
                }
            }
        }

        // Case 2: split into 3 rectangles (L-shapes / cross cuts)
        if (m >= 2 && n >= 2) {
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    // Split into: top + bottom-left + bottom-right
                    ans = Math.min(ans, lt[i][n] + lb[i][j] + rb[i][j]);
                    // Split into: left + top-right + bottom-right
                    ans = Math.min(ans, lt[i][j] + rt[i][j] + lb[i][n]);
                }
            }
        }
        return ans;
    }

    private int[][] minimumArea(int[][] a) {
        int m = a.length, n = a[0].length;
        // f[i+1][j+1] = minimum rectangle area covering all 1s
        // in submatrix from (0,0) to (i,j)
        int[][] f = new int[m + 1][n + 1];

        // border[j] = info for column j: {row index, left boundary, right boundary}
        int[][] border = new int[n][3];
        for (int j = 0; j < n; j++) border[j][0] = -1;

        for (int i = 0; i < m; i++) {
            int left = -1, right = 0;
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1) {
                    if (left < 0) left = j;
                    right = j;
                }

                int[] preB = border[j];
                if (left < 0) {
                    // current row has no 1s so far → copy from row above
                    f[i + 1][j + 1] = f[i][j + 1];
                } else if (preB[0] < 0) {
                    // first row containing 1s
                    f[i + 1][j + 1] = right - left + 1;
                    border[j][0] = i;
                    border[j][1] = left;
                    border[j][2] = right;
                } else {
                    // merge current row’s [left,right] with previous rows
                    int l = Math.min(preB[1], left);
                    int r = Math.max(preB[2], right);
                    f[i + 1][j + 1] = (r - l + 1) * (i - preB[0] + 1);
                    border[j][1] = l;
                    border[j][2] = r;
                }
            }
        }
        return f;
    }

    // Rotate matrix 90° clockwise
    private int[][] rotate(int[][] a) {
        int m = a.length, n = a[0].length;
        int[][] b = new int[n][m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                b[j][m - 1 - i] = a[i][j];
            }
        }
        return b;
    }
}