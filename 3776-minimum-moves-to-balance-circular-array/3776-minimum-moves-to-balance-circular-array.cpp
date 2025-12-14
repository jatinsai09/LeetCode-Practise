class Solution {
#define ll long long int    
public:
    long long minMoves(vector<int>& bal) {
        ll n = bal.size(), s = 0;

        for (auto &i: bal) {
            s += i;
        }

        if (s < 0) {
            return -1;
        }

        int ni = -1;
        for (int i = 0; i < n; i++) {
            if (bal[i] < 0) {
                ni = i;
                break;
            }
        }

        if (ni == -1) {
            return 0;
        }

        ll res = 0, need = -bal[ni], g;
        for (ll d = 1; d < n; d++) {
            ll took = 0;
            {
                g = min(need, (ll)bal[(ni + d) % n]);
                need -= g;
                took += g;
            }
            {
                g = min(need, (ll)bal[(ni - d + n) % n]);
                need -= g;
                took += g;
            }
            res += took * d;
        }

        return res;
    }
};