class DSU {
    vector<int> size, par;

public:
    DSU(int n) {
        size.resize(n);
        par.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }
    int findPar(int u) {
        if (par[u] == u)
            return u;
        return par[u] = findPar(par[u]);
    }
    void unite(int u, int v) {
        int pu = findPar(u), pv = findPar(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv])
            swap(pu, pv);

        size[pu] += size[pv];
        par[pv] = pu;
    }
};

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        int tot_edges = 0, mn = 1e9;
        priority_queue<vector<int>> non_must; // {wt,u,v}

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2],
                must = edges[i][3];

            if (must == 1) {
                if (dsu.findPar(u) == dsu.findPar(v))
                    return -1;

                dsu.unite(u, v); // include the edge in the graph
                mn = min(mn, wt);
                tot_edges++;
            } else {
                non_must.push({wt, u, v});
            }
        }

        vector<int> vec;
        while (!non_must.empty() && tot_edges < n - 1) {
            auto top = non_must.top();
            non_must.pop();
            int wt = top[0], u = top[1], v = top[2];

            if (dsu.findPar(u) == dsu.findPar(v))
                continue;

            dsu.unite(u, v); // include edge
            vec.push_back(wt);
            tot_edges++;
        }

        if (tot_edges < n - 1)
            return -1;

        sort(vec.begin(), vec.end());
        // upgrade the k minimum ones
        for (int i = 0; i < min(k, (int)vec.size()); i++) {
            vec[i] *= 2;
        }

        // choose the min val
        for (auto& x : vec) {
            mn = min(mn, x);
        }

        return mn;
    }
};
