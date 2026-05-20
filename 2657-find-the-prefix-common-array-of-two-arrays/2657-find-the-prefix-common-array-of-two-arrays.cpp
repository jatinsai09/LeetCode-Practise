class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), c = 0;
        vector<int> res(n), f(n + 1);

        for (int i = 0; i < n; i++) {
            if (++f[A[i]] == 2) {
                c++;
            }
            if (++f[B[i]] == 2) {
                c++;
            }
            res[i] = c;
        }
        return res;
    }
};