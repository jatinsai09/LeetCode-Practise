class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), p = 0;
        vector<int> vis(n);

        auto dfs = [&](auto&& dfs, int u) -> void {
            vis[u] = 1;
            for (int v = 0; v < n; v++) {
                if (!vis[v] && isConnected[u][v]) {
                    dfs(dfs, v);
                }
            }
        };

        for (int u = 0; u < n; u++) {
            if (!vis[u]) {
                p++;
                dfs(dfs, u);
            }
        }

        return p;
    }
};