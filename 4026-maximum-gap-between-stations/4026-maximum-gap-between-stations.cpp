class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size(), m = station.size();

        vector<int> pre(n), suf(n);
        for (int i = 0, j = 0; j < m && i < n; j++) {
            if (skill[i] == station[j]) {
                pre[i] = j;
                i++;
            }
        }
        for (int i = n - 1, j = m - 1; j >= 0 && i >= 0; j--) {
            if (skill[i] == station[j]) {
                suf[i] = j;
                i--;
            }
        }
        
        int res = 0;
        for (int i = 0; i + 1 < n; i++) {
            res = max(res, suf[i + 1] - pre[i]);
        }
        return res;
    }
};