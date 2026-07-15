class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int nextBuy = 0, nextSell = 0, curBuy, curSell;
        for (int ind = n - 1; ind >= 0; ind--) {
           
            curBuy = max(-prices[ind] + nextSell, nextBuy);
            curSell = max(prices[ind] + nextBuy, nextSell);

            nextBuy = curBuy;
            nextSell = curSell;
        }

        return curBuy;
    }
};