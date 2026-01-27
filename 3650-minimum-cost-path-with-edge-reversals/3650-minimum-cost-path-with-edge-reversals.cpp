class Solution {
#define pii pair<int, int>    
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pii>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (u == n - 1) {
                return d;
            }

            if (d > dist[u]) {
                continue;
            }

            for (auto& [v, w] : adj[u]) {
                if (d + w < dist[v]) {
                    pq.push({d + w, v});
                    dist[v] = d + w;
                }
            }
        }
        return -1;
    }
};