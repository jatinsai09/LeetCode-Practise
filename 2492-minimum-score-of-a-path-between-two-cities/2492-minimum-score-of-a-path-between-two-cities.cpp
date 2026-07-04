class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &r : roads){
            int u = r[0], v = r[1];
            int d = r[2];

            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }

        vector<bool> vis(n + 1);
        queue<int> q;

        q.push(1);
        vis[1] = true;
        int res = INT_MAX;
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto &[v, d] : adj[u]){
                res = min(res, d);

                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        return res;
    }
};