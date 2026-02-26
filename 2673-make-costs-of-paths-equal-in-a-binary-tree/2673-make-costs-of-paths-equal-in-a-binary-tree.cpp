class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int res = 0;
        
        function<int(int)> dfs = [&](int node) -> int {
            int left = 2 * node + 1, right = 2 * node + 2;

            if (left >= n) {
                return cost[node];
            }

            int lc = dfs(left);
            int rc = dfs(right);

            res += abs(lc - rc);

            return cost[node] + max(lc, rc);
        };

        dfs(0);
        return res;
    }
};