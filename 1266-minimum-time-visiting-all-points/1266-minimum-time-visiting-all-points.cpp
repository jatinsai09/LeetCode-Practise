class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& pts) {
        int n = pts.size(), res = 0;

        for (int i = 1; i < n; i++) {
            res += max(abs(pts[i][0] - pts[i-1][0]), abs(pts[i][1] - pts[i-1][1]));
        }
        return res;
    }
};