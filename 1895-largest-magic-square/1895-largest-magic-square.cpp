class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int& i, int& j, int& side) {
        vector<int> row(side, 0), col(side, 0);
        int diag1 = 0, diag2 = 0;

        for (int p = i; p < i + side; p++) {
            for (int q = j; q < j + side; q++) {
                row[p - i] += grid[p][q];
                col[q - j] += grid[p][q];
            }
        }

        for (int p = i; p < i + side; p++) {
            diag1 += grid[p][j + p - i];
            diag2 += grid[p][j + side - 1 - p + i];
        }

        int target = row[0];

        for (int p = 0; p < row.size(); p++)
            if (row[p] != target || col[p] != target)
                return false;

        return diag1 == diag2 && diag2 == row[0];
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for (int side = min(m, n); side >= 2; side--) {
            for (int i = 0; i <= m - side; i++) {
                for (int j = 0; j <= n - side; j++) {
                    if (isMagicSquare(grid, i, j, side))
                        return side;
                }
            }
        }

        return 1;
    }
};