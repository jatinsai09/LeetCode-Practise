class Solution {
public:
    bool is_sorted(vector<int>& v) {
        int n = v.size();
        for (int i = 1; i < n; i++) {
            if (v[i] < v[i - 1]) {
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& a) {
        int n = a.size(), res = 0;
        while (!is_sorted(a)) {
            int mn = 1e9, ind = -1;
            for (int i = 0; i < n - 1; i++) {
                if (a[i] + a[i + 1] < mn) {
                    mn = a[i] + a[i + 1];
                    ind = i;
                }
            }

            a[ind] += a[ind + 1];
            a.erase(begin(a) + (ind + 1));
            n--;
            res++;
        }
        return res;
    }
};