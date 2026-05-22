class Solution {
public:
    string removeKdigits(string num, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        string res = "";
        for (auto& c : num) {
            while (!res.empty() && k > 0 && res.back() > c) {
                res.pop_back();
                k--;
            }

            if (!res.empty() || c != '0') {
                res.push_back(c);
            }
        }

        while (!res.empty() && k--) {
            res.pop_back();
        }

        return res.empty() ? "0" : res;
    }
};