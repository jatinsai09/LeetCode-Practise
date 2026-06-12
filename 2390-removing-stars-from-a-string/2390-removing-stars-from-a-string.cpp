class Solution {
public:
    string removeStars(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        string res = "";
        for (auto &c: s) {
            if (c == '*') {
                res.pop_back();
            } else {
                res += c;
            }
        }
        return res;
    }
};