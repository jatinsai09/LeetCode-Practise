class Solution {
#define ll long long int    
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));

        ll mh = 1, mv = 1, prev = hBars[0] - 1, c = 0;
        for (auto &p: hBars) {
            if (p == prev + 1) {
                c++;
                prev++;
            } else {
                mh = max(mh, c + 1);
                prev = p;
                c = 1;
            }
        }
        mh = max(mh, c + 1);

        prev = vBars[0] - 1, c = 0;
        for (auto &p: vBars) {
            if (p == prev + 1) {
                c++;
                prev++;
            } else {
                mv = max(mv, c + 1);
                prev = p;
                c = 1;
            }
        }
        mv = max(mv, c + 1);

        ll s = min(mh, mv);

        return s * s;
    }
};