class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        set<int> st;
        for (auto &b: buildings) {
            st.insert(b[0]);
            st.insert(b[1]);
        }

        map<int, int> ind;
        int idx = 0;
        for (auto p: st) {
            ind[p] = idx++;
        }

        int n = st.size();
        vector<vector<int>> start(n), end(n);
        for (auto &b: buildings) {
            int l = b[0], r = b[1], h = b[2];

            start[ind[l]].push_back(h);
            end[ind[r]].push_back(h);
        }

        vector<vector<int>> res;
        vector<int> x(st.begin(), st.end());
        multiset<int> ms;
        int prev = 0;

        for (int i = 0; i < n; i++) {
            for (auto &h: start[i]) {
                ms.insert(h);
            }
            for (auto &h: end[i]) {
                auto it = ms.find(h);
                if (it != ms.end()) {
                    ms.erase(it);
                }
            }

            int mh = (ms.empty() ? 0 : *ms.rbegin());

            if (prev != mh) {
                res.push_back({x[i], mh});
            }
            prev = mh;
        }

        return res;
    }
};