class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), res = 0;

        for (int i = 0; i < n; i++) {
            vector<int> f(26);

            int maxi = INT_MIN;
            for (int j = i; j < n; j++) {
                maxi = max(maxi, ++f[s[j] - 'a']);
                int mini = INT_MAX;
                for (const auto& i: f) {
                    if (!i) {
                        continue;
                    }
                    mini = min(mini, i);
                }

                res += (maxi - mini);
            }
        }
        return res;
    }
};