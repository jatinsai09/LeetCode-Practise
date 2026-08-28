class Solution {
public:
    int numFriendRequests(vector<int>& arr) {
        vector<int> f(121);
        for (const auto& i : arr) {
            f[i]++;
        }

        int res = 0;
        for (int a = 1; a <= 120; a++) {
            if (f[a] == 0) {
                continue;
            }
            for (int b = 1; b <= 120; b++) {
                if (f[b] == 0) {
                    continue;
                }

                if (req(a, b)) {
                    res += f[a] * (f[b] - (a == b));
                }
            }
        }
        return res;
    }

    bool req(int a, int b) {
        return !(b <= 0.5 * a + 7 || b > a);
    }
};