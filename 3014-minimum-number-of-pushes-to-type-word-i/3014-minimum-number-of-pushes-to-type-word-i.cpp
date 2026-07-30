class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size(), res = 0;

        for (int i = 0; i < n; i++) {
            res += 1 + (i / 8);
        }

        return res;
    }
};