class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size(), m = discounts.size();

        sort(rbegin(prices), rend(prices));
        sort(rbegin(discounts), rend(discounts));

        double res = 0;
        int k = min(n, m);

        for (int i = 0; i < k; i++) {
            res += (double)prices[i] * (100 - discounts[i]) / 100;
        }

        for (int i = k; i < n; i++) {
            res += prices[i];
        }
        return res;
    }
};