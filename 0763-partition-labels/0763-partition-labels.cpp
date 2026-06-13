class Solution {
public:
    vector<int> partitionLabels(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<char, int> li;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            li[s[i]] = i;
        }

        vector<int> res;
        int prev = -1, maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, li[s[i]]);
            if (maxi == i) {
                res.push_back(i - prev);
                prev = i;
            }
        }
        return res;
    }
};