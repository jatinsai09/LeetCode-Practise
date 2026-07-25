class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<int>> res;
        vector<int> v;

        function<void(int, int)> f = [&](int start, int rem) -> void {
            if (v.size() == k) {
                if (rem == 0) {
                    res.push_back(v);
                }
                return;
            }
            if (rem < 0) {
                return;
            }

            for (int i = start; i <= 9; i++) {
                v.push_back(i);
                f(i + 1, rem - i);
                v.pop_back();
            }
        };

        f(1, n);
        return res;
    }
};