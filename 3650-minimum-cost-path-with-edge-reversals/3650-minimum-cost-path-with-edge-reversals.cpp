class Solution {
#define pii pair<int, int>    
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pii>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], 2 * e[2]});
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