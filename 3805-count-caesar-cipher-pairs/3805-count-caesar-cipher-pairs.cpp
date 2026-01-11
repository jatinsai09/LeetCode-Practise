class Solution {
#define ll long long    
public:
    long long countPairs(vector<string>& words) {
        ll n = words.size(), m = words[0].size(), res = 0;
        unordered_map<string, ll> f;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                string got = "";
                for (int k = 0; k < m; k++) {
                    int key = words[i][k] - 'a';
                    int newKey = (key + j) % 26;
                    got += char('a' + newKey);
                }
                res += f[got];
            }
            f[words[i]]++;
        }

        return res;
    }
};