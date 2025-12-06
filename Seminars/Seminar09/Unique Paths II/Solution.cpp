class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return 0;
        int row = grid.size();
        int col = grid[0].size();
        if (grid[row - 1][col - 1] == 1) return 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) grid[i][j] = -1;
            }
        }

        grid[0][0] = 1;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 && j == 0) continue;
                if (grid[i][j] == -1) continue;

                long long up = 0;
                if (i - 1 >= 0 && grid[i - 1][j] != -1)
                    up = grid[i - 1][j];

                long long left = 0;
                if (j - 1 >= 0 && grid[i][j - 1] != -1)
                    left = grid[i][j - 1];

                long long ans = up + left;
                grid[i][j] = (int)ans;
            }
        }

        return grid[row - 1][col - 1];
    }
};