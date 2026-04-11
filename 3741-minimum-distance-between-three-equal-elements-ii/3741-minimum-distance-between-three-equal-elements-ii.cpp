class Solution {
public:
    int minimumDistance(vector<int>& a) {
        int n = a.size(), res = INT_MAX;
        vector<vector<int>> ind(n + 1, vector<int>(2, -1));

        for (int i = 0; i < n; i++) {

            if(ind[a[i]][0] != -1) {
                res = min(res, 2 * (i - ind[a[i]][0]));
            }
            
            ind[a[i]][0] = ind[a[i]][1];
            ind[a[i]][1] = i;
        }

        return (res == INT_MAX ? -1 : res);
    }
};