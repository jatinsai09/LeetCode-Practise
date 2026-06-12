class Solution {
public:
    bool closeStrings(string word1, string word2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> f1(26, 0), f2(26, 0);

        for (char c : word1) {
            f1[c - 'a']++;
        }
        for (char c : word2) {
            f2[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if ((f1[i] > 0) != (f2[i] > 0)) {
                return false;
            }
        }

        sort(begin(f1), end(f1));
        sort(begin(f2), end(f2));

        return f1 == f2;
    }
};