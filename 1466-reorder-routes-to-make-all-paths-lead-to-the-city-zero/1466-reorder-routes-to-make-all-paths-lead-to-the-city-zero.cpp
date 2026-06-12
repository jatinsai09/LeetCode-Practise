class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<int> vis(n);
        for (auto &e: connections) {
            adj[e[0]].push_back(-e[1]);
            adj[e[1]].push_back(e[0]);
        }

        function<int(int)> dfs = [&](int u) -> int {
            int res = 0;
            vis[u] = 1;
            for (auto &v: adj[u]) {
                if (!vis[abs(v)]) {
                    res += dfs(abs(v)) + (v < 0);
                }
            }
            return res;
        };

        return dfs(0);
    }
};