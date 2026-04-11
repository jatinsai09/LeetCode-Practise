class Solution {
public:
    int minimumDistance(vector<int>& a) {
        int n = a.size(), res = INT_MAX;
        vector<vector<int>> ind(n + 1);

        for (int i = 0; i < n; i++) {
            int sz = ind[a[i]].size();
            if(sz > 1) {
                res = min(res, 2 * (i - ind[a[i]][sz - 2]));
            }
            ind[a[i]].push_back(i);
        }


        return (res == INT_MAX ? -1 : res);
    }
};