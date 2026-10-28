class Solution {
#define ll long long int
const ll mod = 1e9 + 7;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(begin(horizontalCuts), end(horizontalCuts));
        sort(begin(verticalCuts), end(verticalCuts));

        ll mh = 0, mw = 0;

        ll ph = 0;
        for (auto &i: horizontalCuts) {
            mh = max(mh, i - ph);
            ph = i;
        }
        mh = max(mh, h - ph);

        ll pw = 0;
        for (auto &i: verticalCuts) {
            mw = max(mw, i - pw);
            pw = i;
        }
        mw = max(mw, w - pw);

        return (mh * mw) % mod;
    }
};