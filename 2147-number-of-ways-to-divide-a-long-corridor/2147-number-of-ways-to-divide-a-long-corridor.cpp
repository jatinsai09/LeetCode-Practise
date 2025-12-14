class Solution {
#define ll long long int
const ll mod = 1000000007;
public:
    int numberOfWays(string s) {
        ll n = s.size(), res = 1, seats = 0, plants = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'S') {
                if (++seats > 1 && seats % 2) {
                    res *= (plants + 1);
                    res %= mod;
                }
                plants = 0;
            } else {
                plants++;
            }
        }

        return seats % 2 == 0 && seats > 0 ? res : 0;
    }
};