class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n);
        queue<int> q;
        q.push(source);
        vis[source] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (u == destination) {
                return true;
            }

            for (auto& v : adj[u]) {
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }

        return false;
    }
};