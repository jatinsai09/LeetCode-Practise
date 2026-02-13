class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size(), res = 0;

        map<pair<int, int>, int> vis;
        vis[{0, 0}] = -1;
        int a = 0, b = 0, cnt = 0;

        for (int i = 0; i < n; i++) {
            cnt = (i == 0 || s[i] == s[i - 1] ? cnt + 1 : 1);
            if (s[i] == 'a') {
                a++;
            }
            else if (s[i] == 'b') {
                b++;
            }
            else {
                a--;
                b--;
            }

            res = max(res, cnt);
            if (vis.count({a, b})) {
                res = max(res, i - vis[{a, b}]);
            } else {
                vis[{a, b}] = i;
            }
        }

        auto give = [&](char x, char y) -> void {
            map<int, int> mp;
            int d = 0;
            mp[0] = -1;

            for (int i = 0; i < n; i++) {
                if (s[i] != x && s[i] != y) {
                    d = 0;
                    mp.clear();
                    mp[0] = i;
                    continue;
                }

                d = (s[i] == x ? d + 1 : d - 1);

                if (mp.count(d)) {
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