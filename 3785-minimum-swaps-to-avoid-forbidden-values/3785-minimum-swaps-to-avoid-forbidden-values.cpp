class Solution {
public:
    int minSwaps(vector<int>& a, vector<int>& fb) {
        int n = a.size(), k = 0;
        unordered_map<int, int> f1, f2;

        for (int i = 0; i < n; i++) {
            if (a[i] == fb[i]) {
                k++;
            }
            f1[a[i]]++;
            f2[fb[i]]++;
        }
        
        if (k == 0) {
            return 0;
        }

        int mx = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (a[i] == fb[i]) {
                int x = a[i];
                mp[x]++;
                mx = max(mx, mp[x]);
                if (f1[x] > n - f2[x] || f2[x] > n - f1[x]) {
                    return -1;
                }
            }
        }

        int res = (k + 1) / 2;
        if (k == mx){
            return k;
        }
        if (mx > k - mx + 1) {
            res += k - mx;
        }
        
        return res;
    }
};