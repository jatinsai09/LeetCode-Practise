class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int N = 1105;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> prev(m, vector<bool>(N, false));
        prev[0][grid[0][0]] = true;

        for (int i = 0; i < n; i++) {
            vector<vector<bool>> cur(m, vector<bool>(N, false));
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    cur[0][grid[0][0]] = true;
                    continue;
                }

                for (int xr = 0; xr < N; xr++) {
                    if ((i > 0 && prev[j][xr]) || (j > 0 && cur[j - 1][xr])) {
                        cur[j][xr ^ grid[i][j]] = true;
                    }
                }
            }

            prev = cur;
        }

        for (int xr = 0; xr < N; xr++) {
            if (prev[m - 1][xr]) {
                return xr;
            }
        }

        return -1;
    }
};