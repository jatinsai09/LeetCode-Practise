class Solution {
public:
    int minPartitions(string s) {
        int n = s.size(), res = 1;

        for (int i = 0; i < n; i++) {
            res = max(res, s[i] - '0');
        }

        return res;
    }
};