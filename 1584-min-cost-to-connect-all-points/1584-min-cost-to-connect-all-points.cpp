class Solution {
#define pii pair<int, int>
public:
    int minCostConnectPoints(vector<vector<int>>& pts) {
        int n = pts.size(), res = 0;
        vector<bool> vis(n);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        pq.push({0, 0});
        while (!pq.empty()) {
            auto [wt, u] = pq.top();
            pq.pop();

            if (vis[u]) {
                continue;
            }
            vis[u] = true;
            res += wt;

            for (int v = 0; v < n; v++) {
                if (vis[v]) {
                    continue;
                }

                int wt = abs(pts[u][0] - pts[v][0]) + abs(pts[u][1] - pts[v][1]);
                pq.push({wt, v});
            }

        }
        return res;
    }
};