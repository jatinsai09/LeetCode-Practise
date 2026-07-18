class Solution {
#define ll long long int
#define pii pair<ll, ll>
const ll mod = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<pii>> adj(n);
        for (const auto& it : roads) {
            adj[it[0]].emplace_back(it[1], it[2]);
            adj[it[1]].emplace_back(it[0], it[2]);
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<ll> dist(n, 1e12), ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        //{dist,vertex}
        pq.push({0, 0});
        // E logV
        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            for (const auto& [adjNode, edW] : adj[node]) {
                // This is the first time I am coming
                //  with this short distance
                if (dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    
                    ways[adjNode] = ways[node];
                } else if (dis + edW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};