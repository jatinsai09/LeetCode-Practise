class Solution {
public:
    int help(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (ind == prices.size()) {
            return 0;
        }
        if (dp[ind][buy] != -1) {
            return dp[ind][buy];
        }

        int profit = 0;
        if (buy) {
            profit = max(-prices[ind] + help(ind + 1, 0, prices, dp),
                         help(ind + 1, 1, prices, dp));
        } else {
            profit = max(prices[ind] + help(ind + 1, 1, prices, dp),
                         help(ind + 1, 0, prices, dp));
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        // vector<int> ahead(2, 0), cur(2, 0);
        // dp[n][0] = dp[n][1] = 0;
        // ahead[0] = ahead[1] = 0;

        int aBuy = 0, aNotBuy = 0, curBuy, curNotBuy;

        for (int ind = n - 1; ind >= 0; ind--) {
            /*for (int buy = 1; buy >= 0; buy--) {
                //int profit = 0;
                if (buy) {
                     profit = max(-prices[ind] + dp[ind + 1][1 - buy],
                                  dp[ind + 1][buy]);

                    profit = max(-prices[ind] + ahead[1 - buy], ahead[buy]);
                } else {
                     profit = max(prices[ind] + dp[ind + 1][1 - buy],
                                  dp[ind + 1][buy]);

                    profit = max(prices[ind] + ahead[1 - buy], ahead[buy]);
                }
                dp[ind][buy] = profit;

                cur[buy] = profit;
                ahead = cur;
            }*/

            curBuy = max(-prices[ind] + aNotBuy, aBuy);
            curNotBuy = max(prices[ind] + aBuy, aNotBuy);

            aBuy = curBuy;
            aNotBuy = curNotBuy;
        }

        return aBuy;
    }
};