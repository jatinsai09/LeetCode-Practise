class Solution {
public:
    int minimumDeletions(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int res = 0, cb = 0;
        for (auto &c: s) {
            if (c == 'a') {
                res = min(cb, res + 1);
            } else {
                cb++;
            }
        }
        return res;
    }
};