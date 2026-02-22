class Solution {
#define ll long long    
public:
    bool isDigitorialPermutation(int n) {
        ll sum = 0, t = n;
        int f[10] = {0};
        
        while (t) {
            int r = t % 10;
            ll fct = 1;
            for (ll i = r; i > 1; i--) {
                fct *= i;
            }
            sum += fct;
            f[r]++;
            t  /= 10;
        }

        
        t = sum;
        while (t) {
            int r = t % 10;
            f[r]--;
            t /= 10;
        }

        for (auto &i: f) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
};