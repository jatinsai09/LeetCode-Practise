class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = positions.size();
        vector<vector<int>> robots;
        vector<int> stk;

        for (int i = 0; i < n; i++) {
            robots.push_back({positions[i], i});
        }
        sort(robots.begin(), robots.end());

        for (auto& robot : robots) {
            int ind = robot[1];
            if (directions[ind] == 'R') {
                stk.push_back(ind);
                continue;
            }

            while (!stk.empty() && healths[ind] > 0) {
                int last = stk.back();
                if (healths[ind] > healths[last]) {
                    stk.pop_back();
                    healths[last] = 0;
                    healths[ind]--;
                } else if (healths[ind] < healths[last]) {
                    healths[ind] = 0;
                    healths[last]--;
                } else {
                    stk.pop_back();
                    healths[ind] = 0;
                    healths[last] = 0;
                }
            }
        }

        vector<int> res;
        for (auto &h: healths) {
            if (h) {
                res.push_back(h);
            }
        }
        return res;
    }
};