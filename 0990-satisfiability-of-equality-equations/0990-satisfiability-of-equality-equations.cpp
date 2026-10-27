class DSU {
public:
    vector<int> parent, size;
    DSU (int n) {
        parent.resize(26);
        size.resize(26);

        for (int i = 0; i < 26; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);

        if (pu == pv) {
            return false;
        }

        if (size[pu] < size[pv]) {
            swap(pu, pv);
        }

        size[pu] += size[pv];
        parent[pv] = pu;

        return true;
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26);

        for (auto &s: equations) {
            int u = (s[0] - 'a'), v = (s[3] - 'a');

            if (s[1] == '=') {
                dsu.unite(u, v);
            }
        }

        for (auto &s: equations) {
            int u = (s[0] - 'a'), v = (s[3] - 'a');

            if (s[1] == '=') {
                continue;
            }

            if (dsu.find(u) == dsu.find(v)) {
                return false;
            }
        }
        return true;
    }
};