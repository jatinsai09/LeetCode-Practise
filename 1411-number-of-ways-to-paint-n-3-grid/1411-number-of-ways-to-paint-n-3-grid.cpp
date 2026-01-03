class Solution {
#define ll long long 
public:
    int numOfWays(int n) {
        const ll MOD = 1e9 + 7;
        ll A = 6, B = 6;

        for (int i = 2; i <= n; i++) {
            ll newA = (2 * A + 2 * B) % MOD;
            ll newB = (2 * A + 3 * B) % MOD;
            A = newA;
            B = newB;
        }

        return (A + B) % MOD;
    }
};