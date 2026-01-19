class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> path;

        auto dfs = [&](auto&& f, int u) -> void {
            path.push_back(u);
            if (u == n - 1) {
                res.push_back(path);
            } else {
                for (auto& v : graph[u]) {
                    f(f, v);
                }
            }
            path.pop_back();
        };

        dfs(dfs, 0);
        return res;
    }
};