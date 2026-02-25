class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> prev(n, vector<int>(k + 1, -1));
        prev[0][0] = 0;

        for (int i = 0; i < m; i++) {
            vector<vector<int>> cur(n, vector<int>(k + 1, -1));
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    if (i == 0 && j == 0 && c == 0) {
                        cur[j][c] = 0;
                        continue;
                    }
                    int nc;
                    if (i > 0) {
                        nc = c - (grid[i][j] > 0);
                        if (nc >= 0 && prev[j][nc] != -1) {
                            cur[j][c] =
                                max(cur[j][c], prev[j][nc] + grid[i][j]);
                        }
                    }
                    if (j > 0) {
                        nc = c - (grid[i][j] > 0);
                        if (nc >= 0 && cur[j - 1][nc] != -1) {
                            cur[j][c] =
                                max(cur[j][c], cur[j - 1][nc] + grid[i][j]);
                        }
                    }
                }
            }
            prev = cur;
        }

        int res = -1;
        for (int c = 0; c <= k; c++) {
            res = max(res, prev[n - 1][c]);
        }
        return res;
    }
};