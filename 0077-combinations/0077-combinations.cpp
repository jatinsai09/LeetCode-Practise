class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> c;

        f(1, c, res, n, k);
        return res;
    }
    void f(int start, auto& c, auto& res, int& n, int& k) {
        if (c.size() == k) {
            res.push_back(c);
            return;
        }

        for (int i = start; i <= n; i++) {
            c.push_back(i);
            f(i + 1, c, res, n, k);
            c.pop_back();
        }
    }
};