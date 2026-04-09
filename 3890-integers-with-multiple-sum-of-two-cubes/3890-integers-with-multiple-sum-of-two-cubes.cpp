class Solution {
#define ll long long int
public:
    vector<int> findGoodIntegers(int n) {
        vector<ll> got;
        vector<int> res;

        ll i3, j3;
        for (ll i = 1; ;i++) {
            i3 = i * i * i;

            if (i3 > n) {
                break;
            }

            for (int j = i; ;j++) {
                j3 = j * j * j;

                ll s = i3 + j3;
                if (s > n) {
                    break;
                }

                got.push_back(s);
            }
        }

        sort(begin(got), end(got));
        int m = got.size(), c;
        for (int i = 0, j; i < m;) {
            j = i;
            c = 0;

            while (j < m && got[i] == got[j]) {
                c++;
                j++;
            }

            if (c >= 2) {
                res.push_back(got[i]);
            }
            i = j;
        }

        return res;
    }
};