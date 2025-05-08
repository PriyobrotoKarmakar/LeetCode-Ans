class Solution {
    public int minTimeToReach(int[][] moveTime) {
        int rows = moveTime.length;
        int cols = moveTime[0].length;

        int[][] timeToReach = new int[rows][cols];
        for (int[] row : timeToReach) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{0, 0, 0, 1});

        int[][] directions = new int[][]{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int currentTime = current[0];
            int currentRow = current[1];
            int currentCol = current[2];
            int stepTime = current[3];

            if (currentRow == rows - 1 && currentCol == cols - 1) {
                return currentTime;
            }

            for (int[] direction : directions) {
                int newRow = currentRow + direction[0];
                int newCol = currentCol + direction[1];

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    int newTime = Math.max(currentTime + stepTime, moveTime[newRow][newCol] + stepTime);

                    if (newTime < timeToReach[newRow][newCol]) {
                        timeToReach[newRow][newCol] = newTime;
                        pq.offer(new int[]{newTime, newRow, newCol, stepTime == 1 ? 2 : 1});
                    }
                }
            }
        }

        return -1;
    }
}