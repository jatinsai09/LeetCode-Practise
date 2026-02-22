class Solution {
#define ll long long int    
public:
    ll make_key(int x, int y, int z) {
        x += 100;
        y += 100;
        z += 100;
        return ( (ll)x << 40 ) | ( (ll)y << 20 ) | z;
    }
    int countSequences(vector<int>& a, long long k) {
        ll n = a.size();

        auto factors = [&](ll x) -> vector<int> {
            vector<int> p(3, 0);

            while (x % 2 == 0) {
                p[0]++;
                x /= 2;
            }
            while (x % 3 == 0) {
                p[1]++;
                x /= 3;
            }
            while (x % 5 == 0) {
                p[2]++;
                x /= 5;
            }

            if (x > 1) {
                return {-1};
            }
            return p;
        };

        vector<int> need = factors(k);
        if (need[0] == -1) {
            return 0;
        }

        vector<vector<int>> pf(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            pf[i] = factors(a[i]);
        }

        ll res = 0;
        unordered_map<ll, ll> l, r;
        
        function<void(int, int, int, int, int, unordered_map<ll, ll>&)> dfs = [&](int i, int end, int e2, int e3, int e5, auto& mp) {
            if (i == end) {
                mp[make_key(e2, e3, e5)]++;
                return;
            }

            dfs(i + 1, end, e2, e3, e5, mp);

            dfs(i + 1, end,
               e2 + pf[i][0],
               e3 + pf[i][1],
               e5 + pf[i][2],
               mp);

            dfs(i + 1, end,
               e2 - pf[i][0],
               e3 - pf[i][1],
               e5 - pf[i][2],
               mp);
        };

        int m = n / 2;
        
        dfs(0, m, 0, 0, 0, l);
        dfs(m, n, 0, 0, 0, r);

        for (auto &it: l) {
            ll key = it.first, cnt = it.second;

            int x = ((key >> 40) & ((1<<20)-1)) - 100;
            int y = ((key >> 20) & ((1<<20)-1)) - 100;
            int z = (key & ((1<<20)-1)) - 100;

            ll req = make_key(need[0] - x, need[1] - y, need[2] - z);

            if (r.count(req)) {
                res += cnt * r[req];
            }
        }
        return res;
    }
};