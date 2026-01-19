class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int limit) {
        int m = mat.size(), n = mat[0].size(), res = 0;

        vector<vector<int>> pre(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pre[i][j] = mat[i - 1][j - 1] + pre[i - 1][j] + pre[i][j - 1] -
                            pre[i - 1][j - 1];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                int l = 0, r = min(m - i, n - j), m;
                while (l <= r) {
                    m = l + (r - l) / 2;

                    int sum = pre[i + m][j + m] - pre[i + m][j - 1] -
                              pre[i - 1][j + m] + pre[i - 1][j - 1];

                    if (sum <= limit) {
                        res = max(res, m + 1);
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }
            }
        }

        return res;
    }
};