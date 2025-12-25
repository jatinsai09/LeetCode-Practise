class Solution {
public:
    void f(string digits, vector<string>& v, vector<string>& res, string s,
           int l) {
        if (l == digits.size()) {
            res.push_back(s);
            return;
        }

        int n = digits[l] - '0';
        for (int i = 0; i < v[n].size(); i++) {
            s += v[n][i];
            f(digits, v, res, s, l + 1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }

        vector<string> v = {"",    "",    "abc",  "def", "ghi",
                            "jkl", "mno", "pqrs", "tuv", "wxyz"};

        int l = 0;
        vector<string> res;
        string s = "";

        f(digits, v, res, s, l);

        return res;
    }
};