class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<int>> r(m + 2, vector<int>(n + 2)), c(r), d1(r), d2(r);

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                r[i][j] += grid[i - 1][j - 1] + r[i][j - 1];
                c[i][j] += grid[i - 1][j - 1] + c[i - 1][j];
                d1[i][j] += grid[i - 1][j - 1] + d1[i - 1][j - 1];
                d2[i][j] += grid[i - 1][j - 1] + d2[i - 1][j + 1];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = min(m - i, n - j); k > res; k--) {
                    int sum = d1[i + k][j + k] - d1[i - 1][j - 1];
                    bool yes = sum == (d2[i + k][j] - d2[i - 1][j + k + 1]);

                    for (int l = 0; l <= k && yes; l++) {
                        yes &= sum == (r[i + l][j + k] - r[i + l][j - 1]);
                        yes &= sum == (c[i + k][j + l] - c[i - 1][j + l]);
                    }

                    res = yes ? k : res;
                }
            }
        }

        return res + 1;
    }
};