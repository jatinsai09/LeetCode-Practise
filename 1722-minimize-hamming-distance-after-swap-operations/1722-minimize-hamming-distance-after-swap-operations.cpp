class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);

        if (px == py) {
            return false;
        }

        if (size[py] < size[px]) {
            parent[py] = px;
            size[px] += size[py];
        } else {
            parent[px] = py;
            size[py] += size[px];
        }
        return true;
    }
};
class Solution {
public:
    int minimumHammingDistance(vector<int>& src, vector<int>& tgt,
                               vector<vector<int>>& as) {
        int n = src.size();
        DSU dsu(n);

        for (auto& swap : as) {
            dsu.unite(swap[0], swap[1]);
        }

        unordered_map<int, unordered_map<int, int>> gf;
        for (int i = 0; i < n; i++) {
            gf[dsu.find(i)][src[i]]++;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int root = dsu.find(i);
            auto& f = gf[root];

            if (f[tgt[i]]) {
                f[tgt[i]]--;
            } else {
                res++;
            }
        }

        return res;
    }
};