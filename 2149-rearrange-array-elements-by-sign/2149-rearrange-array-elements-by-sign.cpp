class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        int n = a.size(), i = 0, j = 1;
        vector<int> res(n);

        for (int k = 0; k < n; k++) {
            if (a[k] > 0) {
                res[i] = a[k];
                i += 2;
            } else {
                res[j] = a[k];
                j += 2;
            }
        }

        return res;
    }
};