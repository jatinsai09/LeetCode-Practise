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

        queue<tuple<int, int, int>> q;
        vector<int> dist(n, 1e7);

        q.push({0, src, 0});
        dist[src] = 0;
        // E = flights.size();
        while (!q.empty()) {
            auto [stops, node, cost] = q.front();
            q.pop();

            if (stops > k) {
                continue;
            }

            for (auto& [adjNode, edW] : adj[node]) {
                if (cost + edW < dist[adjNode] && stops <= k) {
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, adjNode, dist[adjNode]});
                }
            }
        }

        if (dist[dst] == 1e7) {
            return -1;
        }
        return dist[dst];
    }
};