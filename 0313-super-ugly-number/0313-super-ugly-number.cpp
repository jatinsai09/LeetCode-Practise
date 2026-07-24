class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1) {
            return 1;
        }

        int np = primes.size();
        vector<int> pi(np, 0), res(n);

        res[0] = 1;
        for (int i = 1; i < n; i++) {
            long mn = INT_MAX, got;

            for (int j = 0; j < np; j++) {
                got = 1LL * primes[j] * res[pi[j]];
                if (got < mn) {
                    mn = got;
                } 
            }

            res[i] = (int)mn;
            for (int j = 0; j < np; j++) {
                if (1LL * primes[j] * res[pi[j]] == mn) {
                    pi[j]++;
                }
            }
        }
        return res[n - 1];
    }
};