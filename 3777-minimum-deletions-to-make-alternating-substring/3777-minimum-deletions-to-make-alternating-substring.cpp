class Solution {
public:
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> bits(n + 1, 0);

        auto update = [&](int ind, int val) -> void {
            ind++;
            while (ind <= n) {
                bits[ind] += val;
                ind += (ind & -ind);
            }
        };

        auto query = [&](int ind) -> int {
            ind++;
            int sum = 0;
            while (ind > 0) {
                sum += bits[ind];
                ind -= (ind & -ind);
            }
            return sum;
        };

        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == s[i + 1]) {
                update(i, 1);
            }
        }

        vector<int> res;
        for (const auto& q : queries) {
            if (q[0] == 1) {
                int i = q[1];
                {
                    if (i - 1 >= 0 && s[i - 1] == s[i]) {
                        update(i - 1, -1);
                    }
                    if (i + 1 < n && s[i] == s[i + 1]) {
                        update(i, -1);
                    }
                }
                s[i] = (s[i] == 'A' ? 'B' : 'A');
                {
                    if (i - 1 >= 0 && s[i - 1] == s[i]) {
                        update(i - 1, 1);
                    }
                    if (i + 1 < n && s[i] == s[i + 1]) {
                        update(i, 1);
                    }
                }
            } else {
                int l = q[1], r = q[2];
                int sum = query(r - 1) - query(l - 1);
                res.push_back(sum);
            }
        }

        return res;
    }
};