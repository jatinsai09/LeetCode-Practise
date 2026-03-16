class Solution {
#define ll long long int
public:
    long long countCommas(long long n) {
        ll s = 1, d = 1, e, res = 0;

        while (s <= n) {
            e = s * 10 - 1;
            e = min(e, n);

            ll c = (d - 1) / 3;
            if (c) {
                res += (e - s + 1) * c;
            } 
            s *= 10;
            d++;
        }

        return res;
    }
};