class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size(), res = 0;

        sort(begin(costs), end(costs), [&](const auto& a, const auto& b){
            return (a[0] - a[1]) < (b[0] - b[1]);
        });

        for (int i = 0; i < n; i++) {
            res += costs[i][(i >= n / 2)];
        }
        return res;
    }
};