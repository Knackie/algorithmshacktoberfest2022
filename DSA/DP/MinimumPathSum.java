public class MinimumPathSum {
    public int minPathSum(int[][] grid) {

        int m = grid.length;
        int n = grid[0].length;

        int[][] dp = new int [m][n];

        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[0].length; j++) {
                dp[i][j] = -1;
            }
        }

        return MinimumPathSum (0, 0, m, n, grid, dp);
    }

    static int MinimumPathSum (int i, int j, int m, int n, int[][] grid, int[][] dp) {

        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        if (i == m || j == n) {
            return Integer.MAX_VALUE;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = MinimumPathSum (i, j + 1, m, n, grid, dp);
        int down  = MinimumPathSum (i + 1, j, m, n, grid, dp);

        dp[i][j] = grid[i][j] + Math.min (right, down);
        return dp[i][j];
    }
}