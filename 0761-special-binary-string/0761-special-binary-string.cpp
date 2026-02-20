class Solution {
public:
    string makeLargestSpecial(string s) {
        int n = s.size(), bal = 0;

        vector<string> blocks;
        for (int l = 0, r = 0; r < n; r++) {
            bal += (s[r] == '1' ? 1 : -1);

            if (bal == 0) {
                string ss = s.substr(l + 1, r - l - 1);
                string got = "1" + makeLargestSpecial(ss) + "0";

                blocks.push_back(got);
                l = r + 1;
            }
        }
        sort(rbegin(blocks), rend(blocks));

        string res = "";
        for (auto &b: blocks) {
            res += b;
        }
        return res;
    }
};