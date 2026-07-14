class Solution {

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& it : times) {
            int u = it[0], v = it[1], wt = it[2];
            adj[u].push_back({v, wt});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n + 1, 1e9);
        
        pq.push({0, k});
        dist[k] = 0;
        while (!pq.empty()) {
            auto [curDist, curNode] = pq.top();
            pq.pop();

            for (auto& [adjNode, wt] : adj[curNode]) {
                if (curDist + wt < dist[adjNode]) {
                    pq.push({curDist + wt, adjNode});
                    dist[adjNode] = curDist + wt;
                }
            }
        }

        int mx = *max_element(begin(dist) + 1, end(dist));
        return mx == 1e9 ? -1 : mx;
    }
};