class Solution {
public:
    vector<vector<int>> permute(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> res;

        function<void(int)> f = [&](int ind) -> void {
            if (ind == n) {
                res.push_back(a);
                return;
            }

            for (int i = ind; i < n; i++) {
                swap(a[i], a[ind]);
                f(ind + 1);
                swap(a[i], a[ind]);
            }
        };

        f(0);
        return res;
    }
};