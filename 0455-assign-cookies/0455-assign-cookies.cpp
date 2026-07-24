class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        sort(begin(g), end(g));
        sort(begin(s), end(s));

        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                i++;
            }
            j++;
        }
        return i;
    }
};