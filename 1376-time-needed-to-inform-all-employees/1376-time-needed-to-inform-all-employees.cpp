class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }

        function<int(int)> dfs = [&](int u) -> int {
            int maxTime = 0;
            for (auto &v: adj[u]) {
                maxTime = max(maxTime, dfs(v));
            }

            return informTime[u] + maxTime;
        };

        return dfs(headID);
    }
};