class DSU {
public:    
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i <= n; i++){
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
        if (size[px] < size[py]) {
            parent[px] = py;
            size[py] += px;
        } else {
            parent[py] = px;
            size[px] += py;
        }
        return true;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cn = connections.size();
        if (cn < n - 1) {
            return -1;
        }

        DSU dsu(n + 1);
        int x, y, extra = 0;
        for (const auto& it : connections) {
            x = it[0], y = it[1];
        
            extra += (dsu.unite(x, y) == false);
        }

        int cc = 0;
        for (int i = 0; i < n; i++) {
            cc += (i == dsu.parent[i]);
        }

        int req = cc - 1;
        return (extra < req ? -1 : req);
    }
};