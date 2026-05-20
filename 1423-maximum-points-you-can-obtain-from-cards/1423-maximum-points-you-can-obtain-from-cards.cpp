class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size(), res = 0;
        for (int i = 0; i < k; i++) {
            res += cp[i];
        }

        int cur = res;
        for (int i = k - 1; i >= 0; i--) {
            cur -= cp[i];
            cur += cp[n - (k - i)];

            res = max(res, cur);
        }
        return res;
    }
};