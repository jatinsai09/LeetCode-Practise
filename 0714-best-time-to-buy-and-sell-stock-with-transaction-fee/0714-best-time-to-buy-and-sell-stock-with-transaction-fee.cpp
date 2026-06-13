class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int prevBuy = INT_MIN, prevSell = 0, curBuy, curSell;

        for (int i = 0; i < n; i++) {
            curBuy = max(-(prices[i] + fee) + prevSell, prevBuy);
            curSell = max(prices[i] + prevBuy, prevSell);

            prevBuy = curBuy;
            prevSell = curSell;
        }
        return prevSell;
    }
};