class Solution {
#define ll long long
#define vll vector<ll>
#define pii pair<int, int>
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pii>> adj(n + 1);
        for (auto &e: edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

        priority_queue<vll, vector<vll>, greater<vll>> pq;
        vector<vll> dist(n, vll(k, LLONG_MAX));

        dist[0][k - 1] = 0;
        pq.push({0, 0, k - 1});
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            ll d = it[0], u = it[1], rem = it[2];
            if (u == n - 1) {
                return d;
            }

            for (auto &it: adj[u]) {
                int v = it.first, w = it.second;
                if (labels[u] == labels[v]) {
                    if (rem && dist[v][rem - 1] > d + w) {
                        dist[v][rem - 1] = d + w;
                        pq.push({dist[v][rem - 1], v, rem - 1});
                    } 
                } else {
                    if (dist[v][k - 1] > d + w) {
                        dist[v][k - 1] = d + w;
                        pq.push({dist[v][k - 1], v, k - 1});
                    }
                }
            }

        }

        return -1;
    }
};