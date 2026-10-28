class Solution {
#define ll long long int
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = ids.size();

        vector<vector<string>> res;

        unordered_map<string, ll> cv;
        unordered_map<string, int> cmv;

        ll mxs = 0;
        for (int i = 0; i < n; i++) {
            cv[creators[i]] += views[i];

            if (!cmv.count(creators[i])) {
                cmv[creators[i]] = i;
            } else {
                int &cmvi = cmv[creators[i]];

                if (views[cmvi] < views[i]) {
                    cmvi = i;
                } else if (views[cmvi] == views[i] && ids[i] < ids[cmvi]) {
                    cmvi = i;
                }
            }

            mxs = max(mxs, cv[creators[i]]);
        }

        for (auto &[ci, vs]: cv) {
            if (vs == mxs) {
                res.push_back({ci, ids[cmv[ci]]});
            }
        }

        return res;
    }
};