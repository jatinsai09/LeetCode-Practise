class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> cur = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        for (int i = 2; i <= n; i++) {
            vector<int> next;
            for (auto& x : cur) {
                int d = x % 10;
                if (d + k < 10) {
                    next.push_back(x * 10 + (d + k));
                }
                if (k && d - k >= 0) {
                    next.push_back(x * 10 + (d - k));
                }
            }
            cur = next;
        }

        return cur;
    }
};