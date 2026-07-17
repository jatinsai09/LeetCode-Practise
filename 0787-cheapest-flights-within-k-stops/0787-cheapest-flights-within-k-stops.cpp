class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<pair<int, int>>> adj(n);
        for (const auto& it : flights) {
            adj[it[0]].emplace_back(it[1], it[2]);
        }

        queue<pair<int, int>> q;
        vector<int> dist(n, 1e7);
        int stops = 0;

        q.push({0, src});
        dist[src] = 0;
        // E = flights.size();
        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [cost, node] = q.front();
                q.pop();

                for (const auto& [adjNode, edW] : adj[node]) {
                    if (cost + edW < dist[adjNode]) {
                        dist[adjNode] = cost + edW;
                        q.push({dist[adjNode], adjNode});
                    }
                }
            }

            if (stops == k) {
                break;
            }
            stops++;
        }

        if (dist[dst] == 1e7) {
            return -1;
        }
        return dist[dst];
    }
};