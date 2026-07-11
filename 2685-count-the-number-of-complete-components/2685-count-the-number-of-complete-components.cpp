class Solution {
public:
    void dfs(int i, const vector<vector<int>>& adj, vector<bool>& vis,
         int& nn, int& ne) {

        vis[i] = true;

        nn++;
        ne += adj[i].size();
        for (const auto& nbr : adj[i]) {
            if (vis[nbr]) {
                continue;
            }
            dfs(nbr, adj, vis, nn, ne);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nn = 0, ne = 0;
                dfs(i, adj, vis, nn, ne);
                res += (nn * (nn - 1) == ne);
            }
        }
        return res;
    }
};