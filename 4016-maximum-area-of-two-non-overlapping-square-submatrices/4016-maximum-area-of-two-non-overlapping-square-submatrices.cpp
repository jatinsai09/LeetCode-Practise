class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> dp(m, vector<int>(n));
        int mx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!mat[i][j]) {
                    continue;
                }

                if (!i || !j) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
                mx = max(mx, dp[i][j]);
            }
        }

        vector<int> mxr(mx + 2, -1), mnr(mx + 2, m), mxc(mx + 2, -1), mnc(mx + 2, n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int k = dp[i][j];
                if (k) {
                    mxr[k] = max(mxr[k], i);
                    mnr[k] = min(mnr[k], i);
                    mxc[k] = max(mxc[k], j);
                    mnc[k] = min(mnc[k], j);
                }
            }
        }
        
        for (int k = mx; k > 0; k--) {
            mxr[k] = max(mxr[k], mxr[k + 1]);
            mnr[k] = min(mnr[k], mnr[k + 1]);
            mxc[k] = max(mxc[k], mxc[k + 1]);
            mnc[k] = min(mnc[k], mnc[k + 1]);

            if ((mxr[k] - mnr[k]) >= k || (mxc[k] - mnc[k] >= k)) {
                return k * k;
            }
        }

        return 0;
    }
};