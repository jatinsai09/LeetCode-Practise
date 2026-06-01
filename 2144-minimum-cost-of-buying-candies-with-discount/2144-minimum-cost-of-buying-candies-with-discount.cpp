class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(begin(cost), end(cost));
        int n = cost.size(), i = n - 1, total = 0;

        while (i > 0) {
            total += cost[i] + cost[i - 1];
            i -= 3;
        }
        if (i == 0) {
            total += cost[0];
        }
        return total;
    }
};