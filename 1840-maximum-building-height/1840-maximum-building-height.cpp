class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& rest) {
        rest.push_back({1, 0});
        rest.push_back({n, n - 1});
        sort(begin(rest), end(rest));

        auto f = [&](auto& rest) -> int {
            int mx = 0;

            for (int i = 0; i + 1 < rest.size(); i++) {
                int cp = rest[i][0], ch = rest[i][1];

                int np = rest[i + 1][0], nh = rest[i + 1][1];

                int d = np - cp;
                int ph = ch + abs(d);

                if (ph > nh) {
                    ph = nh + (ph - nh) / 2;
                }

                mx = max(mx, ph);

                rest[i + 1][1] = min(ph, nh);
            }
            return mx;
        };


        f(rest);

        reverse(begin(rest), end(rest));

        return f(rest);
    }
};