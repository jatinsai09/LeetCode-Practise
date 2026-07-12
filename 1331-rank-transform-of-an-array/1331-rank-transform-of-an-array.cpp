class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) {
            return {};
        }

        vector<pair<int, int>> vp;

        for (int i = 0; i < n; i++) {
            vp.push_back({arr[i], i});
        }
        sort(begin(vp), end(vp), [&](auto& a, auto& b){
            return a.first < b.first;
        });

        vector<int> res(n);
        res[vp[0].second] = 1;
        for (int i = 1; i < n; i++) {
            int cur = vp[i].first, prev = vp[i - 1].first;

            res[vp[i].second] = res[vp[i - 1].second] + (prev != cur);
        }

        return res;
    }
};