class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> cur(2, vector<int>(3, 0));
        vector<vector<int>> after(2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 1; buy >= 0; buy--) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy) {
                        cur[buy][cap] = max(-prices[i] + after[1 - buy][cap],
                                            after[buy][cap]);
                    } else {
                        cur[buy][cap] = max(prices[i] + after[1 - buy][cap - 1],
                                            after[buy][cap]);
                    }
                }
            }
            after = cur;
        }
        return after[1][2];
    }
};