class DSU {
    public: vector < int > parent,
    size;
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
        }
        else {
            parent[px] = py;
            size[py] += size[px];
        }
        return true;
    }
};
class Solution {
public:
    int maxActivated(vector<vector<int>>& pts) {
        int n = pts.size();
        DSU dsu(n);

        unordered_map<int, int> xi, yi;
        for (int i = 0; i < n; i++) {
            int x = pts[i][0], y = pts[i][1];

            if (xi.count(x)) {
                dsu.unite(i, xi[x]);
            } else {
                xi[x] = i;
            }

            if (yi.count(y)) {
                dsu.unite(i, yi[y]);
            } else {
                yi[y] = i;
            }
        }

        unordered_map<int, int> cs;
        for (int i = 0; i < n; i++) {
            int par = dsu.find(i);
            cs[par] = dsu.size[par];
        }

        vector<int> sz;
        for (auto &i: cs) {
            sz.push_back(i.second);
        }
        
        int m = sz.size();
        if (m == 1) {
            return sz[0] + 1;
        }

        sort(rbegin(sz), rend(sz));
        return sz[0] + sz[1] + 1;
    }
};