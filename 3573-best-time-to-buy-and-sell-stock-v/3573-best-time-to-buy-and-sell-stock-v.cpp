class Solution {
#define ll long long  
public:
    long long maximumProfit(vector<int>& prices, int k) {
        ll n = prices.size(), mn = -1e14;
        ll dp[n + 1][k + 1][3];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int s = 0; s <= 2; s++) {
                    dp[i][j][s] = mn;
                }
            }
        }

        function<ll(int, int, int)> f = [&](int i, int k, int s) -> ll {
            if (i == n || k == 0) {
                return s == 0 ? 0 : mn;
            }

            if (dp[i][k][s] != mn) {
                return dp[i][k][s];
            }

            ll p = prices[i], profit = f(i + 1, k, s); // Take rest;

            if (s == 0) { // start a transaction
                profit = max(profit, f(i + 1, k, 1) - p); // Normal transaction
                profit = max(profit, f(i + 1, k, 2) + p); // Short selling transaction
            } else {
                if (s == 1) { // Complete normal transaction
                    profit = max(profit, f(i + 1, k - 1, 0) + p);
                } else { // Complete short selling transaction
                    profit = max(profit, f(i + 1, k - 1, 0) - p);
                }
            }

            return dp[i][k][s] = profit;
        };

        return f(0, k, 0);
    }
};