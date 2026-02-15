class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.size(), res = 1;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    if (len <= 2) {
                        dp[i][j] = 0;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                } else {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }

                if (dp[i][j] < 2) {
                    res = max(res, len);
                }
            }
        }

        return res;
    }
};