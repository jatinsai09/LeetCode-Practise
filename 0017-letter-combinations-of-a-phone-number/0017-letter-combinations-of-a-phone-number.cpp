class Solution {
public:
    void f(string& digits, vector<string>& v, vector<string>& res, string s, int l) {
        if (l == digits.size()) {
            res.push_back(s);
            return;
        }

        int n = digits[l] - '0';
        for (auto &c: v[n]) {
            s += c;
            f(digits, v, res, s, l + 1);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> v = {"",    "", "abc",  "def", "ghi",
                            "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> res;

        f(digits, v, res, "", 0);

        return res;
    }
};