class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> ispal(n, vector<bool>(n));

        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;

                if (s[i] != s[j]) {
                    continue;
                }

                if (len <= 3 || ispal[i + 1][j - 1]) {
                    ispal[i][j] = true;
                }
            }
        }

        vector<int> dp(n);
        for (int j = 0; j < n; j++) {
            if (j) {
                dp[j] = dp[j - 1];
            }

            for (int i = j - k + 1; i >= 0; i--) {
                if (ispal[i][j]) {
                    dp[j] = max(dp[j], (i ? dp[i - 1] : 0) + 1);
                    break;
                }
            }
        }

        return dp[n - 1];
    }
};