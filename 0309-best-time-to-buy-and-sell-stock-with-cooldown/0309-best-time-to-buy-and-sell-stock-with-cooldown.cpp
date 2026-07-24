class Solution {
public:
    // int dpp[5005][2];

    // int f(int ind, int buy, vector<int>& prices) {
    //     if (ind >= prices.size()) {
    //         return 0;
    //     }
    //     if (dpp[ind][buy] != -1) {
    //         return dpp[ind][buy];
    //     }
    //     int profit = 0;
    //     if (buy) {
    //         profit = max(-prices[ind] + f(ind + 1, 0, prices),
    //                      f(ind + 1, 1, prices));
    //     } else {
    //         profit =
    //             max(prices[ind] + f(ind + 2, 1, prices), f(ind + 1, 0, prices));
    //     }

    //     return dpp[ind][buy] = profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //memset(dpp, -1, sizeof(dpp));
        //vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        vector<int> front2(2), front1(2), cur(2);

        for (int ind = n - 1; ind >= 0; ind--) {
            /*for (int buy = 1; buy >= 0; buy--) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[ind] + dp[ind + 1][1 - buy],
                                 dp[ind + 1][buy]);
                } else {
                    profit = max(prices[ind] + dp[ind + 2][1 - buy],
                                 dp[ind + 1][buy]);
                }
                dp[ind][buy] = profit;
            }*/

            //dp[ind][1] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
            //dp[ind][0] = max(prices[ind] + dp[ind + 2][1], dp[ind + 1][0]);

            cur[1] = max(-prices[ind] + front1[0], front1[1]);
            cur[0] = max(prices[ind] + front2[1], front1[0]);
            front2 = front1;
            front1 = cur;
        }
        return cur[1];
    }
};