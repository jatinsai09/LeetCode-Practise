class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> mp = {"", "", "abc", "def", "ghi",
                            "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> res;

        function<void(string, int)> f = [&](string s, int i) -> void {
            if (i == n) {
                res.push_back(s);
                return;
            }

            int d = digits[i] - '0';
            for (const auto& c: mp[d]) {
                s.push_back(c);
                f(s, i + 1);
                s.pop_back();
            }
        };

        f("", 0);
        return res;
    }
};