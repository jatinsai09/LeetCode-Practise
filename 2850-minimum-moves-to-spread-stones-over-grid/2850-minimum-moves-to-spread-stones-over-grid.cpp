class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n = 3, c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                c += (grid[i][j] == 0);
            }
        }
        if (c == 0) {
            return 0;
        }

        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    continue;
                }

                for (int a = 0; a < n; a++) {
                    for (int b = 0; b < n; b++) {
                        if (grid[a][b] > 1) {
                            int got = abs(i - a) + abs(j - b);

                            grid[i][j]++;
                            grid[a][b]--;
                            res = min(res, got + minimumMoves(grid));
                            grid[i][j]--;
                            grid[a][b]++;
                        }
                    }
                }
            }
        }
        return res;
    }
};