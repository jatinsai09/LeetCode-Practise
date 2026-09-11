class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> f(10);
        for (const auto &i: digits) {
            f[i]++;
        }

        int res = 0;
        for (int i = 0; i < 10; i += 2) {
            if (!f[i]) {
                continue;
            }

            f[i]--;
            int c = 0;
            for (int j = 0; j < 10; j++) {
                if (!f[j]) {
                    continue;
                }

                f[j]--;

                for (int k = 1; k < 10; k++) {
                    c += (f[k] > 0);
                }

                f[j]++;
            }
        
            f[i]++;

            res += c;
        }
        return res;
    }
};