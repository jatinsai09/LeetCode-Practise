class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size(), mn = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(budget + 1, -1));
        vector<int> free(n);

        function<int(int, int)> f = [&](int i, int t) -> int {
            if (i == n) {
                return t / mn;
            }
            if (dp[i][t] != -1) {
                return dp[i][t];
            }

            int take = 0;
            if (t >= items[i][1]) {
                take = 1 + free[i] + f(i + 1, t - items[i][1]);
            }

            int not_Take = f(i + 1, t);

            return dp[i][t] = max(take, not_Take);
        };

        for (int i = 0; i < n; i++) {
            mn = min(mn, items[i][1]);
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    free[i]++;
                }
            }
        }

        return f(0, budget);
    }
};