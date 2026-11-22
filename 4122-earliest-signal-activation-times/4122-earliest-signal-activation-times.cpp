class Solution {
#define ll long long int
#define pll pair<ll, ll>
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& rs) {
        vector<ll> res(n, -1);
        res[0] = 0;

        vector<vector<pll>> adj(n);
        for (auto &e: edges) {
            ll u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
        }
        
        priority_queue<pll, vector<pll>, greater<>> pq;
        for (auto &[v, wt]: adj[0]) {
            pq.push({wt, v});
        }

        while (!pq.empty()) {
            auto [time, u] = pq.top();
            pq.pop();
            if (res[u] >= 0) {
                continue;
            }

            if (--rs[u] == 0) {
                res[u] = time;
                for (auto &[v, wt]: adj[u]) {
                    pq.push({time + wt, v});
                }
            }
        }

        return res;
    }
};