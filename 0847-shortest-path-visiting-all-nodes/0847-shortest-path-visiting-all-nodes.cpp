class Solution {
struct State {
    int msk, u, d;
};
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), fin = (1 << n) - 1;
        queue<State> q;
        unordered_set<int> vis;
        
        for (int i = 0; i < n; ++i) {
            q.push({1 << i, i, 0});
            vis.insert((1 << i) * 16 + i);
        }
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            if (cur.msk == fin) {
                return cur.d;
            }
            
            for (auto& v : graph[cur.u]) {
                int new_msk = cur.msk | (1 << v);
                int hash = new_msk * 16 + v;
                
                if (vis.find(hash) == vis.end()) {
                    vis.insert(hash);
                    q.push({new_msk, v, cur.d + 1});
                }
            }
        }
        
        return -1;
    }
};