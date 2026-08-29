class Solution {
public:
    int findMaxForm(vector<string>& strs, int zeros, int ones) {
        vector<vector<int>> dp(ones + 1, vector<int>(zeros + 1));

        for (const auto& s : strs) {
            int c0 = 0, c1 = 0;
            for (const auto &ch: s) {
                c0 += (ch == '0');
                c1 += (ch == '1');
            }

            for (int i = ones; i >= c1; i--) {
                for (int j = zeros; j >= c0; j--) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - c1][j - c0]);
                }
            }
        }

        return dp[ones][zeros];
    }
};