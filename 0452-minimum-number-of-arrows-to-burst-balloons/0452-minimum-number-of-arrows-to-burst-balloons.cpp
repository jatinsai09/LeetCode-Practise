class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points), end(points));

        int n = points.size(), cnt = 0, i = 0;
        while (i < n) {
            int s = points[i][0], e = points[i][1];
            while (i < n && points[i][0] <= e) {
                e = min(e, points[i][1]);
                i++;
            }
            cnt++;
        }
        return cnt;
    }
};