class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 1;

        double slope;
        for (int i = 0; i < n; i++) {
            unordered_map<double, int> mp;
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2) {
                    slope = DBL_MAX;
                } else {
                    slope = (double)(y2 - y1) / (x2 - x1);
                }
                mp[slope]++;
            }

            for (auto& [_, c] : mp) {
                res = max(res, c + 1);
            }
        }
        return res;
    }
};