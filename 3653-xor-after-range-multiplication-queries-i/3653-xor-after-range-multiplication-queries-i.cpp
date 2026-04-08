class Solution {
const int mod = 1e9 + 7;    
#define ll long long int    
public:
    int xorAfterQueries(vector<int>& a, vector<vector<int>>& queries) {
        int n = a.size(), q = queries.size();
        vector<ll> b(n);
        for(int i = 0; i < n ; i++) {
            b[i] = a[i];
        }
        
        for(auto& qr: queries) {
            for(int ind = qr[0]; ind <= qr[1]; ind += qr[2]) {
                b[ind] = (ll)(b[ind] * qr[3]) % mod;
            }
        }

        ll xr = 0;
        for(auto &i:b){
            xr ^= i;
        }
        return (int)xr;
    }
};