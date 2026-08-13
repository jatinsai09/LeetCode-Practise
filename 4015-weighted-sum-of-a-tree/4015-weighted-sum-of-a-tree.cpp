class Solution {
#define ll long long int
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        ll n = nums.size();

        vector<ll> depth(n, 1);
        ll h = 1;
        
        vector<vector<int>> adj(n); 
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto &v: adj[u]) {
                depth[v] = depth[u] + 1;
                h = max(h, depth[v]);
                q.push(v);
            }
        }

        ll res = 0;
        for (int i = 0; i < n; i++) {
            res += 1LL * nums[i] * (h - depth[i] + 1);
        }

        return res;
    }
};