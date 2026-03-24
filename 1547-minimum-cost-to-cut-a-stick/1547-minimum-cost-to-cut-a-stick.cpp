class Solution {
public:
    int dpp[111][111];
    int help(int s, int e, vector<int>& cuts) {
        if (s > e) {
            return 0;
        }
        if (dpp[s][e] != -1) {
            return dpp[s][e];
        }

        int res = 1e9;
        for (int i = s; i <= e; i++) {
            int cur = (cuts[e + 1] - cuts[s - 1]) + help(s, i - 1, cuts) +
                      help(i + 1, e, cuts);
            res = min(res, cur);
        }
        return dpp[s][e] = res;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(begin(cuts), end(cuts));
        int m = cuts.size(), dp[m + 2][m + 2];
        memset(dp, 0, sizeof(dp));

        cuts.push_back(n);
        cuts.insert(begin(cuts), 0);

        for (int s = m; s >= 1; s--) {
            for (int e = s; e <= m; e++) {
                int res = 1e9;
                for (int i = s; i <= e; i++) {
                    int cur = (cuts[e + 1] - cuts[s - 1]) + dp[s][i - 1] +
                              dp[i + 1][e];
                    res = min(res, cur);
                }
                dp[s][e] = res;
            }
        }
        return dp[1][m];
    }
};