class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        vector<int> dp(n + 1);

        for (int i = n - 1; i >= 0; i--) {
            int cost = INT_MAX;
            for (int j = i; j < n; j++) {
                if (s[i] != s[j]) {
                    continue;
                }

                if (j - i < 3 || pal[i + 1][j - 1]) {
                    pal[i][j] = 1;
                    cost = min(cost, 1 + dp[j + 1]);
                }
            }
            dp[i] = cost;
        }

        return dp[0] - 1;
    }
};