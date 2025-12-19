class Solution {
public:
    #define pii pair<int, int>
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pii>> adj(n);
        for (const auto &meet: meetings) {
            int u = meet[0], v = meet[1], t = meet[2];
            adj[u].push_back({t, v});
            adj[v].push_back({t, u});
        }        

        vector<int> know(n, INT_MAX), res;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});

        while (!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();

            if (know[u] != INT_MAX) {
                continue;
            }

            know[u] = t;
            res.push_back(u);

            for (auto& [mt, v]: adj[u]) {
                if (mt >= t && know[v] == INT_MAX) {
                    pq.push({mt, v});
                } 
            }
        }

        return res;
    }
};