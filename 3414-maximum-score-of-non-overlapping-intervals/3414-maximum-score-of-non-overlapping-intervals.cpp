class Solution {
public:
    struct Node {
        long long score;
        vector<int> ids;
    };
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int m = intervals.size();

        vector<vector<int>> a;
        {
            for (int i = 0; i < m; i++) {
                if (i && intervals[i] == intervals[i - 1]) {
                    continue;
                }
                a.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
            }

            sort(begin(a), end(a), [&](auto& x, auto& y){
                if (x[0] != y[0]) {
                    return x[0] < y[0];
                }

                return x[3] < y[3];
            });
        }

        int n = a.size();
        vector<int> nxt(n, n);
        {
            for (int i = 0; i < n; i++) {
                int l = i + 1, r = n - 1, m, got = n;
                while (l <= r) {
                    m = l + (r - l) / 2;

                    if (a[m][0] > a[i][1]) {
                        got = m;
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }

                nxt[i] = got;
            }
        }

        vector<vector<Node>> dp(n, vector<Node>(4, {-1, {}}));
        {
            auto better = [&](auto& pick, auto& notPick) -> bool {
                if (pick.score > notPick.score) {
                    return true;
                }

                return pick.score == notPick.score && pick.ids < notPick.ids;
            };

            function<Node(int, int)> f = [&](int ind, int c) -> Node {
                if (c == 4 || ind == n) {
                    return {0, {}};
                }

                if (dp[ind][c].score != -1) {
                    return dp[ind][c];
                }

                Node notPick = f(ind + 1, c);

                Node pick = f(nxt[ind], c + 1);
                pick.score += a[ind][2];
                pick.ids.push_back(a[ind][3]);

                sort(begin(pick.ids), end(pick.ids));

                return dp[ind][c] = better(pick, notPick) ? pick : notPick;
            };

            return f(0, 0).ids;
        }
    }
};