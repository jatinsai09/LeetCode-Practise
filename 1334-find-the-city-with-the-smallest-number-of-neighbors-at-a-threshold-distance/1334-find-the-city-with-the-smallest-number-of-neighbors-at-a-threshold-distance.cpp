class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e8));

        {
            for (int i = 0; i < n; i++) {
                dist[i][i] = 0;
            }
            for (auto& e : edges) {
                int u = e[0], v = e[1], d = e[2];
                dist[u][v] = dist[v][u] = d;
            }
        }

        for (int via = 0; via < n; via++) {
            for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                    dist[u][v] = min(dist[u][v], dist[u][via] + dist[via][v]);
                }
            }
        }

        int res = 0, mn = n;
        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = 0; j < n; j++) {
                c += (dist[i][j] <= distanceThreshold);
            }

            if (c <= mn) {
                res = i;
                mn = c;
            }
        }

        return res;
    }
};