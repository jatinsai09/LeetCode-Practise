class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {

        if (k >= prices.size() >> 1) {
            int profit = 0;
            for (int i = 1; i < prices.size(); i++) {
                if (prices[i] > prices[i - 1]) {
                    profit += prices[i] - prices[i - 1];
                }
            }
            return profit;
        }

        int n = prices.size();

        vector<vector<int>> cur(2, vector<int>(k + 1, 0));
        vector<vector<int>> next(2, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; i--) { 
            for (int buy = 1; buy >= 0; buy--) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy) {
                        cur[buy][cap] = max(-prices[i] + next[1 - buy][cap],
                                            next[buy][cap]);
                    } else {
                        cur[buy][cap] = max(prices[i] + next[1 - buy][cap - 1],
                                            next[buy][cap]);
                    }
                }
            }
            next = cur;
        }
        return next[1][k];
    }
};