class Solution {
#define ll long long int    
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        ll n = bottomLeft.size(), mx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ll x1 = max(bottomLeft[i][0], bottomLeft[j][0]);
                ll x2 = min(topRight[i][0], topRight[j][0]);
                ll y1 = max(bottomLeft[i][1], bottomLeft[j][1]);
                ll y2 = min(topRight[i][1], topRight[j][1]);

                if (x1 < x2 && y1 < y2) {
                    ll s = min(x2 - x1, y2 - y1);
                    mx = max(mx, s * s);
                }
            }
        } 

        return mx;
    }
};