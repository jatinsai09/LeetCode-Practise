#define ll long long
class Fancy {
    int global_mul, global_inc;
    vector<int> v;
    int mod = 1e9 + 7;

public:
    Fancy() {
        global_mul = 1;
        global_inc = 0;
    }

    int binpow(int a, int e) {
        int res = 1;
        while (e > 0) {
            if (e & 1) {
                res = ((ll)res * a) % mod;
            }
            a = ((ll)a * a) % mod;
            e >>= 1;
        }
        return res;
    }
    int modinv(int b) { return binpow(b, mod - 2); }
    int divmod(int a, int b) {
        return ((ll)(a % mod) * (modinv(b) % mod)) % mod;
    }

    void append(int val) {
        val = ((ll)val - global_inc + mod) % mod;
        val = divmod(val, global_mul);
        v.push_back(val);
    }

    void addAll(int inc) { global_inc = ((ll)global_inc + inc) % mod; }

    void multAll(int m) {
        global_mul = ((ll)global_mul * m) % mod;
        global_inc = ((ll)global_inc * m) % mod;
    }

    int getIndex(int idx) {
        if (idx >= v.size())
            return -1;

        int res = v[idx];
        res = ((ll)res * global_mul) % mod;
        res = ((ll)res + global_inc) % mod;

        return res;
    }
};