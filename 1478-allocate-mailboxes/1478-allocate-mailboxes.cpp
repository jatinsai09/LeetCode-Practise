class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        sort(begin(houses), end(houses));
        int n = houses.size();

        vector<vector<int>> cost(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int mh = houses[(i + j) / 2];

                for (int p = i; p <= j; p++) {
                    cost[i][j] += abs(houses[p] - mh);
                }
            }
        }

        int dp[100][100];
        memset(dp, -1, sizeof(dp));

        function<int(int, int)> f = [&](int i, int k) -> int {
            if (i == n) {
                return 0;
            }

            if (dp[i][k] != -1) {
                return dp[i][k];
            }

            int res = INT_MAX;
            if (k == 1) {
                return dp[i][k] = cost[i][n - 1];
            }

            for (int j = i; j + k <= n; j++) {
                res = min(res, cost[i][j] + f(j + 1, k - 1));
            }

            return dp[i][k] = res;
        };

        return f(0, k);
    }
};