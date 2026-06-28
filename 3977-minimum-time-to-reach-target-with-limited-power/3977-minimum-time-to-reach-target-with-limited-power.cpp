class Solution {
#define ll long long
#define pll pair<ll, ll>
#define tlll tuple<ll, ll, ll> 
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pll>> adj(n + 1);
        for (auto &e: edges) {
            int u = e[0], v = e[1], t = e[2];
            adj[u].push_back({v, t});
        }

        vector<vector<ll>> dp(n, vector<ll>(power + 1, 1e16));
        priority_queue<tlll, vector<tlll>, greater<tlll>> pq;

        dp[source][power] = 0;
        pq.push({0, power, source});
        ll tm = 1e16;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            ll t = get<0>(it), p = get<1>(it), u = get<2>(it);

            if (u == target) {
                if (tm == 1e16) {
                    tm = t;
                } 

                if (t > tm) {
                    break;
                }
            }

            if (p < cost[u]) {
                continue;
            }

            int pf = p - cost[u];
            for (auto &[v, tt]: adj[u]) {
                if (dp[v][pf] > t + tt) {
                    dp[v][pf] = t + tt;
                    pq.push({t + tt, pf, v});
                }
            }
        }

        ll mt = 1e16, mp = -1;
        for (int p = 0; p <= power; p++) {
            if (dp[target][p] == 1e16) {
                continue;
            }

            if (dp[target][p] <= mt) {
                mt = dp[target][p];
                mp = p;
            }
        }

        if (mp == -1) {
            return {-1, -1};
        }
        return {mt, mp};
    }
};