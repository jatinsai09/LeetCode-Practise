class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size(), res = n + 1;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int d = abs(i - startIndex);
                res = min({res, d, n - d});
            }
        } 

        return res > n ? -1 : res;
    }
};