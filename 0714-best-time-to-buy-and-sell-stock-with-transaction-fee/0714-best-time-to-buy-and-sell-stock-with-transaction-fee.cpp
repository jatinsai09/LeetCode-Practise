class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int nextBuy = 0, nextSell = 0, curBuy = 0, curSell = 0;

        for (int i = n - 1; i >= 0; i--) {
            curBuy = max(-prices[i] + nextSell, nextBuy);
            curSell = max(prices[i] - fee + nextBuy, nextSell);

            nextBuy = curBuy;
            nextSell = curSell;
        }
        return nextBuy;
    }
};