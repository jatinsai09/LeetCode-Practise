class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), buy = prices[0], profit = 0;
        
        for (int i = 1; i < n; i++) {
            int cur = prices[i] - buy;
            
            if (cur > profit) {
                profit = cur;
            }
            if (prices[i] < buy) {
                buy = prices[i];
            }
        }
        return profit;
    }
};