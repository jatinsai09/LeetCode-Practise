class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size(), res = 0;
        
        vector<int> f(3, 0);
        map<pair<int, int>, int> vis;
        vis[{0, 0}] = -1;
        int p = -1, c = 0;
        
        for (int i = 0; i < n; i++) {
            f[s[i] - 'a']++;
            int np = s[i] - 'a';
            if (p != np) {
                c = 1;
                p = np;
            } else {
                c++;
            }

            int dab = f[0] - f[1];
            int dac = f[0] - f[2];
            int dbc = f[1] - f[2];

            if (vis.find({dab, dac}) != vis.end()) {
                res = max(res, i - vis[{dab, dac}]);
            } else {
                vis[{dab, dac}] = i;
            }

            res = max(res, c);
        }

        auto give = [&](char x, char y) -> void {
            map<int, int> mp;
            int d = 0;
            mp[0] = -1;

            for(int i = 0; i < n; i++) {
                if(s[i] != x && s[i] != y) {
                    d = 0;
                    mp.clear();
                    mp[0] = i;
                    continue;
                }

                if(s[i] == x) {
                    d++;
                } else {
                    d--;
                }

                if(mp.count(d)) {
                    res = max(res, i - mp[d]);
                } else {
                    mp[d] = i;
                }
            }
        };

        give('a', 'b');
        give('b', 'c');
        give('a', 'c');

        
        return res;
    }
};