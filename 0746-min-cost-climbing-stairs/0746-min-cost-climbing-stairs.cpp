class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), first = cost[0], second = cost[1], cur;

        for (int i = 2; i < n; i++) {
            cur = min(first, second) + cost[i];
            first = second;
            second = cur;
        }
        return min(first, second);
    }
};