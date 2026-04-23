class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> p;
        
        func(0, s, p, res);
        return res;
    }

    void func(int ind, string& s, auto& p, auto& res) {
        if (ind == s.size()) {
            res.emplace_back(p);
            return;
        }

        for (int i = ind; i < s.size(); i++) {
            if (ispal(s, ind, i)) {
                p.push_back(s.substr(ind, i - ind + 1));
                func(i + 1, s, p, res);
                p.pop_back();
            }
        }
    }

    bool ispal(string& s, int st, int e) {
        while (st < e) {
            if (s[st++] != s[e--]) {
                return false;
            }
        }
        return true;
    }
};