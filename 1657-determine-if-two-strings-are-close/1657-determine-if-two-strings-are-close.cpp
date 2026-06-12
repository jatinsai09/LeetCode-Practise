class Solution {
public:
    bool closeStrings(string word1, string word2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> f1(26, 0), f2(26, 0), v1(26, 0), v2(26, 0);

        for (char c : word1) {
            f1[c - 'a']++, v1[c - 'a'] = 1;
        }
        for (char c : word2) {
            f2[c - 'a']++, v2[c - 'a'] = 1;
        }
        sort(begin(f1), end(f1));
        sort(begin(f2), end(f2));

        return f1 == f2 && v1 == v2;
    }
};