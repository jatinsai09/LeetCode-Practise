class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size(), canBuy = 0, canSell = 0;

        for (int i = n - 1; i >= 0; i--) {
            canBuy = max(-prices[i] + canSell, canBuy);
            canSell = max(prices[i] - fee + canBuy, canSell);
        }
        return canBuy;
    }
};