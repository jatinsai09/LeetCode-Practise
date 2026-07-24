class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<int> f(n);

        int c = 0, res = 0;
        for (int l = 0, r = 0; r < n; r++) {
            c += (++f[fruits[r]] == 1);

            if (c > 2) {
                c -= (--f[fruits[l++]] == 0);
            }
            
            res = max(res, r - l + 1);
            
        }
        return res;
    }
};
