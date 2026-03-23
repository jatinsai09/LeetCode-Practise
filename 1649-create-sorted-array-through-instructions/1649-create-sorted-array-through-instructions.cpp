class Solution {
public:
    int createSortedArray(vector<int>& ist) {
        const int mod = 1e9 + 7;
        const int N = 100001;
        int f[N];
        memset(f, 0, sizeof(f));

        auto update = [&](int a) -> void {
            while (a < N) {
                f[a]++;
                a += a & -a;
            }
        };

        auto get = [&](int a) -> int {
            int res = 0;
            while (a) {
                res += f[a];
                a -= a & -a;
            }  
            return res;
        };

        int n = 0, res = 0;
        for (auto &i: ist) {
            res = (res + min(get(i - 1), n - get(i))) % mod;
            update(i);
            n++;
        }
        
        return res;
    }
};