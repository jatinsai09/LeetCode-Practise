class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n);
        int p = 0;

        function<void(int)> dfs = [&](int u) -> void {
            vis[u] = 1;
            for (int v = 0; v < n; v++) {
                if (!vis[v] && isConnected[u][v]) {
                    dfs(v);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                p++;
                dfs(i);
            }
        }

        return p;
    }
};