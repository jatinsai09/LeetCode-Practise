class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        return (s + s).substr(1, 2 * s.size() - 2).find(s) != -1;
    }
};