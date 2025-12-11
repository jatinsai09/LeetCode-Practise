class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> mxr(n + 1, 0), mnr(n + 1, n + 1), mxc(n + 1, 0),
            mnc(n + 1, n + 1);

        for (const auto& p : buildings) {
            mxr[p[1]] = max(mxr[p[1]], p[0]);
            mnr[p[1]] = min(mnr[p[1]], p[0]);
            mxc[p[0]] = max(mxc[p[0]], p[1]);
            mnc[p[0]] = min(mnc[p[0]], p[1]);
        }

        int res = 0;
        for (const auto& p : buildings) {
            int yes = 1;
            yes &= (p[0] < mxr[p[1]]);
            yes &= (p[0] > mnr[p[1]]);
            yes &= (p[1] < mxc[p[0]]);
            yes &= (p[1] > mnc[p[0]]);

            res += yes;
        }

        return res;
    }
};