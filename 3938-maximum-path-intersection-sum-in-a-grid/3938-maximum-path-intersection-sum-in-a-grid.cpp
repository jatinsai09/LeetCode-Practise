class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = INT_MIN, cur;

        for (int i = 1; i + 1 < n; i++) {
            for (int j = 1; j + 1 < m; j++) {
                res = max(res, grid[i][j]);
            }
        }

        for (int i = 0; i < n; i++) {
            cur = 0;
            for (int j = 0; j < m; j++) {
                cur += grid[i][j];
                if (j) {
                    cur = max(cur, grid[i][j] + grid[i][j - 1]);
                    res = max(res, cur);
                }
            }
        }

        for (int j = 0; j < m; j++) {
            cur = 0;
            for (int i = 0; i < n; i++) {
                cur += grid[i][j];
                if (i) {
                    cur = max(cur, grid[i][j] + grid[i - 1][j]);
                    res = max(res, cur);
                }
            }
        }
        return res;
    }
};