class Solution {
public:
    bool is_sorted(vector<int>& v) {
        for (int i = 1; i < v.size(); i++) {
            if (v[i] < v[i - 1]) {
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& a) {
        int res = 0;
        while (!is_sorted(a)) {
            int mn = 1e9, ind = -1;
            for (int i = 0; i < a.size() - 1; i++) {
                if (a[i] + a[i + 1] < mn) {
                    mn = a[i] + a[i + 1];
                    ind = i;
                }
            }

            vector<int> b;
            for (int i = 0; i < a.size(); i++) {
                if (i == ind) {
                    b.push_back(a[i] + a[i + 1]);
                    i++;
                } else {
                    b.push_back(a[i]);
                }
            }

            a = b;
            res++;
        }
        return res;
    }
};