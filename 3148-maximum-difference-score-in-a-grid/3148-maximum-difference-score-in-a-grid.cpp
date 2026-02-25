class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = INT_MIN, pmn;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pmn = 1e6;
                if (i) {
                    pmn = grid[i - 1][j];
                }
                if (j) {
                    pmn = min(grid[i][j - 1], pmn);
                }
                res = max(res, grid[i][j] - pmn);
                grid[i][j] = min(grid[i][j], pmn);
            }
        }
        return res;
    }
};