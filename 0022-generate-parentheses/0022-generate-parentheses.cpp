class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;

        function<void(int, int)> f = [&](int open, int close) -> void {
            if (open + close == 0) {
                res.push_back(s);
            }

            if (open) {
                s.push_back('(');
                f(open - 1, close);
                s.pop_back();
            }
            if (close > open) {
                s.push_back(')');
                f(open, close - 1);
                s.pop_back();
            }
        };

        f(n, n);
        return res;
    }
};