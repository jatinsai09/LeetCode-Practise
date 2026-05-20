class Solution {
#define ll long long int
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n);
        ll msk_a = 0, msk_b = 0;

        for (int i = 0; i < n; i++) {
            msk_a |= 1LL << A[i];
            msk_b |= 1LL << B[i];
            res[i] = __builtin_popcountll(msk_a & msk_b);
        }

        return res;
    }
};