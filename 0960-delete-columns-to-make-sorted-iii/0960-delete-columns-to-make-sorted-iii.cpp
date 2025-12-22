class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size(), res = 1;
        vector<int>dp(m, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < i; j++) {
                int yes = 1;
                for (int k = 0; k < n; k++) {
                    if (strs[k][j] > strs[k][i]) {
                        yes = 0;
                        break;
                    }
                }
                if (yes) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }

        return m - res;
    }
};