class DSU{
public:    
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n + 1);
        size.resize(n + 1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y){
        int px = find(x), py = find(y);
        if(px == py){
            return false;
        }
        if(size[py] < size[px]){
            parent[py] = px;
            size[px] += size[py];
        }
        else{
            parent[px] = py;
            size[py] += size[px];
        }
        return true;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int mr = 0, mc = 0;
        for(auto& it : stones){
            mr = max(mr, it[0]);
            mc = max(mc, it[1]);
        }

        DSU dsu(mr + mc + 2);
        unordered_map<int, int> mp;
        for(const auto& it : stones) {
            dsu.unite(it[0], it[1] + mr + 1);
            mp[it[0]] = 1;
            mp[it[1] + mr + 1] = 1;
        }

        int cc = 0;
        for (const auto& it : mp){
            if (dsu.find(it.first) == it.first){
                cc++;
            }
        }

        return n - cc;
    }
};