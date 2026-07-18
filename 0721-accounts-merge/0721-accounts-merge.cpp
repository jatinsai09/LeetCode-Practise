class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++) {
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n + 1);
        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mp.find(accounts[i][j]) != mp.end()) {
                    dsu.unite(i, mp[accounts[i][j]]);
                } else {
                    mp[accounts[i][j]] = i;
                }
            }
        }

        vector<vector<string>> got(n + 1);
        for(const auto& it : mp){
            int ulp = dsu.find(it.second);
            got[ulp].push_back(it.first);
        }

        vector<vector<string>> res;
        for (int i = 0; i < n; i++) {
            if (!got[i].empty()) {
                vector<string> t;
                t.push_back(accounts[i][0]);
                sort(begin(got[i]), end(got[i]));

                for (const auto& s : got[i]) {
                    t.push_back(s);
                }
                res.push_back(t);
            }
        }
        return res;
    }
};