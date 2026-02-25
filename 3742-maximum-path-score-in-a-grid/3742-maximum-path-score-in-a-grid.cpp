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

                    int pc = c - (grid[i][j] > 0);
                    if (pc < 0) {
                        continue;
                    }

                    if (i && prev[j][pc] != -1) {
                        cur[j][c] = max(cur[j][c], prev[j][pc] + grid[i][j]);
                    }
                    if (j && cur[j - 1][pc] != -1) {
                        cur[j][c] = max(cur[j][c], cur[j - 1][pc] + grid[i][j]);
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