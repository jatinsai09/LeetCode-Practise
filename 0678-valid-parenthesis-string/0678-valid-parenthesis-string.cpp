class Solution {
public:
    bool checkValidString(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int bmn = 0, bmx = 0;
        for (const auto &c : s) {
            if (c == '(') {
                bmx++;
                bmn++;
            } else if (c == ')') {
                bmx--;
                bmn--;
            } else {
                bmx++;
                bmn--;
            }

            if (bmx < 0) {
                return false;
            }
            bmn = max(0, bmn);
        }
        return bmn == 0;
    }
};