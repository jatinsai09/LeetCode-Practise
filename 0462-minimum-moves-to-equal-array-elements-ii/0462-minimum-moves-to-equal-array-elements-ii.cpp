class Solution {
public:
    int minMoves2(vector<int>& a) {
        int n = a.size(), res = 0;
        sort(rbegin(a), rend(a));

        for (int i = 0; i < n / 2; i++) {
            res += a[i] - a[n - 1 - i];
        }

        return res;
    }
};