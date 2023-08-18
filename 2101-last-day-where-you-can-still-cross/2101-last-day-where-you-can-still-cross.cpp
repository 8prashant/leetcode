class Solution {
public:
    bool check(int r, int c, int row, int col, vector<vector<int>>& cells) {
        if (r < 0 || r >= row || c < 0 || c >= col || cells[r][c] != 0) {
            return false;
        }
        if (r+1 == row ) {
            return true;
        }
        cells[r][c] = 2;
        bool n = check(r - 1, c, row, col, cells);
        bool s = check(r + 1, c, row, col, cells);
        bool e = check(r, c + 1, row, col, cells);
        bool w = check(r, c - 1, row, col, cells);
        if (n || s || e || w) {
            return true;
        }
        return false;
    }

    bool basestation(int n, int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> v(row, vector<int>(col, 0));
        for (int i = 0; i < n; i++) {
            v[cells[i][0] - 1][cells[i][1] - 1] = 1;
        }
        bool ans = false;
        for (int i = 0; i < col; i++) {
            if (v[0][i] == 0) {
                ans = check(0, i, row, col, v);
                if (ans) {
                    return true;
                }
            }
        }
        return ans;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int i = 0, j = cells.size()-1;
        int ans = 0;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (basestation(mid, row, col, cells)) {
                ans = mid;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return ans;
    }
};