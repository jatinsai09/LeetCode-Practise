class Solution {
#define ll long long int
public:
    long long countCommas(long long n) {
        ll s = 1000, d = 4, e, res = 0;

        while (s <= n) {
            e = min(s * 10 - 1, n);

            ll c = (d - 1) / 3;    
            res += (e - s + 1) * c; 

            s *= 10;
            d++;
        }

        return res;
    }
};