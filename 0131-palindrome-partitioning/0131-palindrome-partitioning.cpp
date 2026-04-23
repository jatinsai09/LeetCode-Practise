class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> res;
        vector<string> p;

        auto isPal = [&](int l, int r) -> bool {
            while (l < r) {
                if (s[l++] != s[r--]) {
                    return false;
                }
            }
            return true;
        };

        function<void(int)> f = [&](int ind) -> void {
            if (ind == n) {
                res.push_back(p);
                return;
            }

            for (int i = ind; i < n; i++) {
                if (isPal(ind, i)) {
                    p.push_back(s.substr(ind, i - ind + 1));
                    f(i + 1);
                    p.pop_back();
                }
            }
        };

        f(0);
        return res;
    }
};